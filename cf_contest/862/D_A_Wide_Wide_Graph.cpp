#include <bits/stdc++.h>
using namespace std;
vector<int> maxDist;
vector<vector<int>> adj;
int n;
vector<int> height;

void dfs1(int cur, int par=-1){
    int maxH = -1;
    for(int i =0;i<adj[cur].size();i++){
        if(adj[cur][i]==par){
            continue;
        }
        dfs1(adj[cur][i],cur);
        maxH = max(maxH, height[adj[cur][i]]);
    }
    height[cur] = 1+maxH;
}

void dfs2(int cur,int par=-1){
    int max1=0,max2=0;
    for(int i:adj[cur]){
        if(i==par){
            continue;
        }
        if(height[i]>max1){
            max2 = max1;
            max1 = height[i];
        }
        else if(max2<height[i]){
            max2 = height[i];
        }
    }
    for(int u:adj[cur]){
        if(u==par){
            continue;
        }
        if(max1 == height[u]){
            maxDist[u] = 1 + max(1+max2,maxDist[cur]);
        }
        else{
            maxDist[u] = 1 + max(1+max1,maxDist[u]);
        }
        dfs2(u,cur);
    }
}

void getMaxDist(){
    height.resize(n,0);
    dfs1(0);
    // for(int i = 0;i<n;i++){
    //     cerr<<height[i]<<" ";
    // }
    // cerr<<endl;
    maxDist[0] = height[0];
    dfs2(0);
    for(int i = 0;i<n;i++){
        maxDist[i] = max(maxDist[i],height[i]);
    }
}


void solve(){
    cin>> n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        // cout<<i<<endl;
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxDist.resize(n,0);
    for(int i = 0;i<n;i++){
        vector<int> dist(n,-1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        int maxDistHere = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int p = 0;p<adj[cur].size();p++){
                if(dist[adj[cur][p]]==-1){
                    dist[adj[cur][p]] = dist[cur] + 1;
                    maxDistHere = max(maxDistHere, dist[cur]+1);
                    q.push(adj[cur][p]);
                }
            }
        }
        maxDist[i] = maxDistHere;
    }

    // getMaxDist();

    sort(maxDist.begin(),maxDist.end());
    // for(int i = 0;i<n;i++){
    //     cerr<<maxDist[i]<<" ";
    // }
    // cerr<<endl;
    vector<int> ans(n);
    int noGroups = 1;
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        while(cnt<n && i>maxDist[cnt]){
            cnt++;
            noGroups++;
            if(cnt==n){
                noGroups--;
            }
        }
        ans[i-1] = noGroups;
        cout<<ans[i-1]<<" ";
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}