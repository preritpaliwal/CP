#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod = 1e9 + 7;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    ll ans = 1;
    for(int i = n-1;i>=0;i--){
        ll l=0,r=n-1,curans=0;
        while(l<=r){
            ll mid = (l+r)/2;
            if(a[mid]>b[i]){
                r = mid-1;
                curans = n-mid;
            }
            else{
                l = mid+1;
            }
        }
        // cerr<<curans<<endl;
        ans *= ((curans-(n-i-1))%mod);
        ans %= mod;
    }
    // cerr<<"done\n";
    cout<<ans%mod<<endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}