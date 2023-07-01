#include <bits/stdc++.h>
using namespace std;


bool search(int s, vector<vector<int>> &adj, vector<int> &p, vector<bool> &vis, vector<bool> &svis){
    priority_queue<pair<int,int>> pq;
    int battles = 0;
    pq.push({-0,s});
    while(!pq.empty()){
        auto _ = pq.top();
        pq.pop();
        if(-_.first>battles){
            return false;
        }
        int cur = _.second;
        battles++;
        vis[cur] = true;
        svis[cur] = true;
        if(adj[cur].empty()){
            return false;
        }
        for(int i = 0;i<adj[cur].size();i++){
            int nc = adj[cur][i];
            if(!vis[nc]){
                pq.push({-p[nc],nc});
                vis[nc] = true;
                svis[nc] = true;
            }
        }
    }
    bool pos = true;
    for(bool p:vis){
        pos &= p;
    }
    return pos;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> p(n,0);
    set<int> starts;
    for(int i = 0;i<n;i++){
        cin>>p[i];
        if(p[i]==0){
            starts.insert(i);
        }
    }
    vector<vector<int>> adj(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<bool> vis(n,false);
    for(int s: starts){
        if(!vis[s]){
            vector<bool> vis2(n,false);
            if(search(s,adj,p,vis2,vis)){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}