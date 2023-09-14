#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    ll sum=0;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    sort(v.begin(),v.end());
    vector<ll> pre(n,0);
    pre[0] = v[0];
    for(ll i =1;i<n;i++){
        pre[i] = pre[i-1]+v[i];
    }
    ll ans = pre[2*k-1];
    for(ll i = 1;i<=k;i++){
        ll left = 0;
        if(k!=i){
            left = pre[2*(k-i)-1];
        }
        ll cur = left + pre[n-1]-pre[n-1-i];
        ans = min(ans,cur);
    }
    cout<<sum-ans<<endl;
}


int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}