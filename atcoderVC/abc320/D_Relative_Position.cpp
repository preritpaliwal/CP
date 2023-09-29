#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
vector<vector<vector<ll>>> adj;

int main(){
    cin>>n>>m;adj.resize(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,x,y;cin>>a>>b>>x>>y;
        adj[a].push_back({b,x,y});adj[b].push_back({a,-x,-y});
    }
    vector<pair<ll,ll>> ans(n+1);
    vector<ll> vis(n+1,0);
    vis[1]=1;
    ans[1]={0,0};
    queue<ll> q;q.push(1);
    while(!q.empty()){
        ll cur=q.front();q.pop();
        for(auto ch:adj[cur]){
            ll idx=ch[0],x=ch[1],y=ch[2];
            if(vis[idx])continue;
            vis[idx]=1;
            ans[idx]={x+ans[cur].first,y+ans[cur].second};
            q.push(idx);
        }
    }
    for(ll i=1;i<=n;i++){
        if(vis[i]){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        else{
            cout<<"undecidable\n";
        }
    }
    return  0;
}