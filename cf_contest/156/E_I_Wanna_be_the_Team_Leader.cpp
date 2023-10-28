#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> b;
vector<pair<ll,ll>> a;
vector<vector<ll>> am;
void solve(){
    cin>>n>>m;
    a.assign(n,{0,0});for(ll i=0;i<n;i++){cin>>a[i].first;a[i].second=i+1;}
    b.assign(m,0);for(ll &i:b)cin>>i;
    sort(a.rbegin(),a.rend());
    am.assign(n,vector<ll> (m,0));
    for(ll i=0;i<m;i++){
        ll r=1;
        for(ll j=0;j<n;j++){
            while(r<=n && a[r-1].first*(r-j)<b[i])r++;
            am[j][i]=r;
        }
    }
    vector<ll> dp((1<<m),n+1);
    vector<ll> ret((1<<m),-1);
    dp[0]=0;
    for(ll mask=1;mask<(1<<m);mask++){
        ll ans=n+1;
        for(ll i=0;i<m;i++){
            if(mask&(1<<i)){
                if(dp[mask^(1<<i)]<n){
                    if(ans>am[dp[mask^(1<<i)]][i]){
                        ans=am[dp[mask^(1<<i)]][i];
                        ret[mask]=i;
                    }
                }
            }
        }
        dp[mask]=ans;
        // cerr<<mask<<" "<<dp[mask]<<"\n";
    }
    if(dp[(1<<m)-1]<=n){
        cout<<"YES\n";
        vector<vector<ll>> ans(m);
        ll mask=(1<<m)-1;
        ll idx = ret[mask];
        while(true){
            ll per = dp[mask^(1<<idx)];
            ll cnt = am[per][idx] - per;
            // cerr<<per<<" "<<cnt<<" "<<idx<<"\n";
            vector<ll> here(cnt+1,cnt);
            for(ll i=1;i<=cnt;i++){
                here[i]=a[i+per-1].second;
            }
            ans[idx] = here;
            mask=mask^(1<<idx);
            idx=ret[mask];
            if(mask==0)break;
        }
        for(ll i=0;i<m;i++){
            for(ll j:ans[i]){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"NO\n";
    }
    return;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}