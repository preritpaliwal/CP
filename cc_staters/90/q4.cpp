#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9+7;
vector<ll> fact;

ll bexp(ll n, ll p,ll m){
    ll ans = 1;
    ll curpow = n;
    while(p!=0){
        if(p&1){
            ans *= curpow;
            ans %= m;
        }
        curpow *= curpow;
        curpow %= m;
        p = p>>1;
    }
    return ans;
}

ll inversemod(ll n){
    ll ans = bexp(n, mod-2,mod);
    return ans;
}

ll printNcR(ll n, ll r){
    if(r>n){
        return 0;
    }
    ll ans = (inversemod(fact[r])*inversemod(fact[n-r]))%mod;
    ans *= fact[n];
    // cout<<"ans: "<<ans<<endl;
    return ans%mod;
}


void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    ll twos = 1;
    for(int i = n-1;i>=0;i--){
        ll cur = printNcR(i,v[i]-1);
        // cout<<"cur: "<<cur<<endl;
        cur *= twos;
        cur %= mod;
        twos *= 2;
        twos %= mod;
        ans += cur;
        ans %= mod;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    fact.resize(1e5 + 3);
    fact[0] = 1;
    for(ll i = 1;i<fact.size();i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}