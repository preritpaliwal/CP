#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    map<ll,vector<ll>> mp;ll n;cin>>n;for(ll i=0;i<n;i++){ll a;cin>>a;mp[a].push_back(i);}
    ll ans=0;
    for(auto &it:mp){
        vector<ll> &ref=it.second;
        if(ref.size()>1){
            ll old=0;
            ll curans=0;
            for(ll i=1;i<ref.size();i++){
                curans+=(ref[i]-ref[i-1]-1)*(i*(ref.size()-i));
            }
            ans+=curans;
        }
    }
    cout<<ans<<endl;
}