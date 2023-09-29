#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> adj(1+n);
    for(int i=0;i<m;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    priority_queue<pair<int,int>> q;
    ll cnt=0;
    vector<int> vis(n+1,0);
    for(int i=0;i<k;i++){int a,b;cin>>a>>b;q.push({b,a});}
    while(!q.empty()){
        auto cur=q.top();q.pop();
        if(vis[cur.second]==1){continue;}
        cnt++;
        vis[cur.second]=1;
        if(cur.first==0)continue;
        for(int ch:adj[cur.second]){
            if(vis[ch]==0){
                q.push({cur.first-1,ch});
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        if(vis[i])cout<<i<<" ";
    }

    return 0;
}