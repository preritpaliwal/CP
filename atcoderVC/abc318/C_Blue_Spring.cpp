#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,d,p;cin>>n>>d>>p;
    vector<ll> f(n+1,0);for(ll i=1;i<=n;i++)cin>>f[i];
    sort(f.begin(),f.end());
    for(ll i=1;i<=n;i++){
        f[i]+=f[i-1];
    }
    ll best=f[n];
    for(ll i=1;i<=n;i++){
        if(i*d<=n){
            // cerr<<f[n-i*d]<<" "<<i<<" "<<p<<" "<<d<<endl;
            best=min(best,f[n-i*d]+i*p);
        }
        else {
            best=min(best,i*p);
            break;
        }
    }
    cout<<best<<endl;
}