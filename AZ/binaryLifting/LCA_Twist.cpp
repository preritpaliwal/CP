#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj,lift;
vector<int> depth;

void dfs(int nn,int pp){
    depth[nn]=1+depth[pp],lift[nn][0]=pp;
    for(int i=1;i<20;i++)lift[nn][i]=lift[lift[nn][i-1]][i-1];
    for(int ch:adj[nn])if(ch!=pp)dfs(ch,nn);
}

int lca(int x,int y){
    if(depth[x]>depth[y])swap(x,y);
    for(int i=19;i>=0;i--)if(((depth[y]-depth[x])&(1<<i)))y=lift[y][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)if(lift[x][i]!=lift[y][i])x=lift[x][i],y=lift[y][i];
    return lift[x][0];
}

int query(){
    int x,y,z;cin>>x>>y>>z;
    int xy=lca(x,y),yz=lca(y,z),xz=lca(x,z);
    return xy^xz^yz;
}

void solve(){
    cin>>n;depth.clear();depth.resize(n+1,0);
    adj.clear();adj.resize(n+1);lift.clear();lift.resize(n+1,vector<int> (20,0));
    for(int i=1;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    dfs(1,0);int q;cin>>q;while(q--)cout<<query()<<endl;;
}

int main(){int t=1;cin>>t;while(t--)solve();return 0;}