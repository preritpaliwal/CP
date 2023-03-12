#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    ll n,k,d,w;
    cin>>n>>k>>d>>w;
    vector<ll> t(n);
    for(ll &i:t){
        cin>>i;
    }
    ll ans = 0;
    ll timeOpen = -1e9;
    ll rem = k;
    for(ll i =0;i<n;i++){
        if(timeOpen+d<t[i]){
            timeOpen = t[i]+w;
            rem = k;
            rem--;
            ans++;
        }
        else{
            rem--;
        }
        if(rem==0){
            timeOpen = -1e9;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}