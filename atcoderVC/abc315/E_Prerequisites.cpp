#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> adj;
vector<int> vis;
vector<int> ans;
void dfs(int nn){
    for(int i:adj[nn]){
        if(vis[i]==1)continue;
        vis[i]=1;
        dfs(i);
        ans.push_back(i);
    }
}
int main(){
    int n;cin>>n;
    adj.resize(n+1);
    vis.resize(n+1,0);
    for(int i=1;i<=n;i++){
        int ci;cin>>ci;
        for(int j=0;j<ci;j++){
            int a;cin>>a;
            adj[i].push_back(a);
        }
    }
    vis[1]=1;
    dfs(1);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}