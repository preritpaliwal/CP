#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int nn, int color){
    int ret=1;
    for(int ch:adj[nn]){if(vis[ch]==-1){vis[ch]=color;ret+=dfs(ch,color);}}
    return ret;
}
int main(){
	int q;cin>>n>>m>>q;adj.resize(n+1),vis.resize(n+1,-1);
    for(int i=0;i<m;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    vector<int> size;int color=0;
    for(int i=1;i<=n;i++)if(vis[i]==-1){vis[i]=color;size.push_back(dfs(i,color++));}
    while(q--){
        int _;cin>>_;
        if(_==1){int a;cin>>a;cout<<size[vis[a]]<<endl;}
        else{int a,b;cin>>a>>b;cout<<((vis[a]==vis[b])?"YES\n":"NO\n");}
    }
}