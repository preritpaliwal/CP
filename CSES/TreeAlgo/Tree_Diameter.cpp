#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> dist;

void dfs(int cur,int par=-1){
    for(int u:adj[cur]){
        if(u!=par){
            dist[u] = dist[cur]+1;
            dfs(u,cur);
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    adj.clear();
    dist.clear();
    adj.resize(n+1);
    dist.resize(n+1,-1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1]=0;
    dfs(1);
    int i_max = 1;
    for(int i = 2;i<=n;i++)if(dist[i_max]<dist[i])i_max = i;
    dist.clear();
    dist.resize(n+1,-1);
    dist[i_max] = 0;
    dfs(i_max);
    int ans = 0;
    for(int i = 1;i<=n;i++)ans = max(ans,dist[i]);
    cout<<ans<<endl;
}