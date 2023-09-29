#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    vector<ll> up{0},sl{0},pre{0};
    ll n;cin>>n;for(ll i=0;i<n;i++){
        ll a;cin>>a;if(a==0)continue;
        if(i%2==1){
            sl.push_back(a);
        }
        else{
            up.push_back(a);
            pre.push_back(up.back()-sl.back()+pre.back());
        }
    }
    ll q;cin>>q;
    while(q--){
        ll a,b;cin>>a>>b;ll ans=0;
        if(a>=b){cout<<0<<endl;continue;}
        ll lidx=upper_bound(sl.begin(),sl.end(),a)-sl.begin()-1;
        ll ridx=lower_bound(up.begin(),up.end(),b)-up.begin();
        ans+=max(0ll,up[lidx]-a);
        ans+=max(0ll,b-sl[ridx]);
        ans+=pre[ridx-1]-pre[lidx];
        cout<<ans<<endl;
    }
    return 0;
}