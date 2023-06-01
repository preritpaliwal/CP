#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans = -1;
    for(ll i = 0;i<n;i++){
        if(i+1==v[i]){
            continue;
        }
        else{
            if(ans==-1){
                ans = abs(v[i]-(i+1));
            }
            else{
                // cout<<"value = "<<abs(v[i]-(i+1));
                ans = __gcd(ans,abs(v[i]-(i+1)));
            }
        }
        // cerr<<"ans: "<<ans<<endl;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}