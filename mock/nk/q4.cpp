#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll &i:v)cin>>i;
    sort(v.begin(),v.end());
    if(n%2==0){
        ll val=(n+1)/2;
        ll ans=0;
        for(ll i=0;i<val;i++){
            ans+=v[n-1-i];
        }
        cout<<ans<<"\n";
    }
    else{
        ll val=(n+1)/2;
        ll ans=0;
        for(int i=0;i<val;i++){
            ans-=v[i];
        }
        cout<<ans<<"\n";
    }
    return ;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}