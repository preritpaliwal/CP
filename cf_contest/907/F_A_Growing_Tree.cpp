#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<pair<ll,ll>>> val(2);
vector<ll> fin;
vector<vector<pair<ll,ll>>> adj(2);
void dfs(ll nn,ll pp){
    
}
void solve(){
    ll q;cin>>q;
    ll sz=1;
    ll time=0;
    while(q--){
        time++;
        ll t;cin>>t;
        if(t==1){
            ll x;cin>>x;
            adj[x].push_back({++sz,time});
            adj.push_back({{x,time}});
        }
        else{
            ll x,v;cin>>x>>v;
            val[x].push_back({v,time});
        }
    }
    dfs(1,0);
    for(int i=1;i<=sz;i++){
        cout<<fin[i]<<" ";
    }
    cout<<"\n";
    return;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        // cerr<<t<<":\n";
        solve();
    }
    return 0;
}