#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int nn){
    int ans=1;
    for(int ch:adj[nn]){
        if(vis[ch]==1)continue;
        vis[ch]=1;
        ans+=dfs(ch);
    }
    return ans;
}

int main(){
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        vis.clear();
        vis.resize(n+1,0);
        vis[i]=1;
        if(dfs(i)==n){
            ans=i;
        }
    }
    cout<<ans<<endl;
}