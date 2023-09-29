#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> a,b;
bool check(ll val){
    ll sell=upper_bound(a.begin(),a.end(),val)-a.begin();
    ll buy=m-(lower_bound(b.begin(),b.end(),val)-b.begin());
    return sell>=buy;
}
int main(){
    cin>>n>>m;
    a.resize(n);b.resize(m);
    for(ll &i:a)cin>>i;
    for(ll &i:b)cin>>i;
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    ll l=0,r=1e9+2;
    ll ans=r;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}