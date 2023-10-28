#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n,t;cin>>n>>t;
    vector<vector<vector<ll>>> adj(t+1,vector<vector<ll>> (n+1));
    for(ll i=1;i<=t;i++){
        ll mi;cin>>mi;
        for(ll k=0;k<mi;k++){
            ll a,b;cin>>a>>b;
            adj[i][a].push_back(b);
            adj[i][b].push_back(a);
        }
    }
    ll k;cin>>k;
    vector<ll> a(k);for(ll i=0;i<k;i++){cin>>a[i];}
    queue<pair<ll,ll>> q;
    q.push({0,1});
    vector<vector<ll>> vis(t+1,vector<ll> (n+1,0));
    vis[a[0]][1]=1;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        ll timeidx=cur.first;
        ll nn=cur.second;
        if(nn==n){
            cout<<timeidx<<"\n";
            return;
        }
        if(timeidx==k-1){
            for(ll ch:adj[a[timeidx]][nn]){
                    q.push({timeidx+1,ch});
            }
                q.push({timeidx+1,nn});
            continue;
        }
        for(ll ch:adj[a[timeidx]][nn]){
            if(vis[a[timeidx+1]][ch]==0){
                q.push({timeidx+1,ch});
                vis[a[timeidx+1]][ch]=1;
            }
        }
        if(vis[a[timeidx+1]][nn]==0){
            q.push({timeidx+1,nn});
            vis[a[timeidx+1]][nn]=1;
        }
    }
    cout<<"-1\n";
    return ;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}