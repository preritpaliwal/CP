#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    ll ntags = 1;
    ll l = b[0],h = a[0]*b[0];
    for(ll i = 1;i<n;i++){
        ll newl = (l*b[i]) / __gcd(l,b[i]);
        ll newh = __gcd(h,a[i]*b[i]);
        if (newh%newl == 0){
            l = newl;
            h = newh;           
        }
        else{
            ntags++;
            l = b[i];
            h = a[i] * b[i];
        }
    }
    cout<<ntags<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}