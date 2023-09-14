#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj,lift,gval;
vector<int> depth,val;
void dfs(int nn,int pp){
    depth[nn]=1+depth[pp],lift[nn][0]=pp,gval[nn][0]=val[nn];
    for(int i=1;i<20;i++){
        lift[nn][i]=lift[lift[nn][i-1]][i-1];
        gval[nn][i]=__gcd(gval[nn][i-1],gval[lift[nn][i-1]][i-1]);
    }
    for(int ch:adj[nn])if(ch!=pp)dfs(ch,nn);
}
void query(){
    int x,y,ans=0;cin>>x>>y;
    if(depth[x]<depth[y])swap(x,y);
    for(int i=19;i>=0;i--)if((depth[x]-depth[y])&(1<<i)){ans=__gcd(ans,gval[x][i]);x=lift[x][i];}
    if(x==y){cout<<__gcd(val[x],ans)<<endl;return;}
    for(int i=19;i>=0;i--){
        if(lift[x][i]!=lift[y][i]){
            ans=__gcd(ans,__gcd(gval[x][i],gval[y][i]));
            x=lift[x][i];y=lift[y][i];
        }
    }
    cout<<__gcd(ans,__gcd(val[lift[x][0]],__gcd(val[x],val[y])))<<endl;
}
void solve(){
    cin>>n;
    adj.clear();adj.resize(n+1);
    lift.clear();lift.resize(n+1,vector<int> (20,0));
    gval.clear();gval.resize(n+1,vector<int> (20,0));
    depth.clear();depth.resize(n+1,-1);
    val.clear();val.resize(n+1,0);
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    dfs(1,0);int q;cin>>q;while(q--)query();
}
int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}