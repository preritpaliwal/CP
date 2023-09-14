#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    a[0] = 0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1){
            a[i]+=a[i-1];
        }
    }
    for(ll i=0;i<q;i++){
        ll l,r;cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;;
    }
}