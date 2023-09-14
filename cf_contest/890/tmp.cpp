#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll ans=0;
    for(int i=n-2;i>=0;i--){
        if(v[i]>v[i+1]){
            ans+=v[i]-v[i+1];
            v[i]=v[i+1];
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}