#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll calc(ll n1,ll n2){
    return n1*n2/__gcd(n1,n2);
}

int main(){
    ll n,x,y;cin>>n>>x>>y;
    vector<pair<ll,ll>> st(n-1);
    ll lcm=1;
    for(ll i=0;i<n-1;i++){
        cin>>st[i].first>>st[i].second;
        lcm=calc(lcm,st[i].first);
    }
    vector<ll> ans(lcm,0);
    for(int t=0;t<lcm;t++){
        ll time=t;
        for(int i=0;i<n-1;i++){
            time=(time/st[i].first + ((time%st[i].first==0)?0:1))*st[i].first+st[i].second;
        }
        ans[t]=time+y-t;
    }
    ll q;cin>>q;
    while(q--){
        ll a;cin>>a;cout<<x+a+ans[(x+a)%lcm]<<endl;
    }
}