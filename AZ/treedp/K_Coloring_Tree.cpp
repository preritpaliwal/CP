#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,k;
vector<vector<pair<ll,ll>>> adj;
vector<ll> dp[2];

void dfs(ll nn,ll pp){
    ll base=0;
    vector<int> dif;
    for(auto ch:adj[nn]){
        if(ch.first==pp)continue;
        dfs(ch.first,nn);
        base+=dp[0][ch.first];
        dif.push_back(-dp[0][ch.first]+dp[1][ch.first]+ch.second);
    }
    sort(dif.begin(),dif.end());
    ll dif0=0;
    ll dif1=0;
	for(int i=1;i<=k;i++){
        if(dif.empty()){
            break;
        }
        dif0+=max(0,dif.back());
        if(i!=k){
            dif1+=max(0,dif.back());
        }
        dif.pop_back();
    }
    dp[0][nn]=base+dif0;
    dp[1][nn]=base+dif1;
}

void solve(){
    cin>>n>>k;
    adj.clear();adj.resize(n+1);
    dp[0].clear();dp[0].resize(n+1);
    dp[1].clear();dp[1].resize(n+1);
    for(ll i=1;i<n;i++){
        ll a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});adj[b].push_back({a,c});
    }
    dfs(1,0);
    cout<<dp[0][1]<<endl;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}