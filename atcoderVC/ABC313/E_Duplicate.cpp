#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(s[i]!='1' && s[i-1]!='1'){
            ans=-1;
        }
    }
    if(ans==-1){
        cout<<ans<<endl;return 0;
    }
    vector<pair<ll,ll>> v;
    ll init=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            init++;
        }
        else{
            v.push_back({init,s[i]-'0'});
            init=0;
        }
    }
    while(!v.empty()){
        ans=(ans+init+1)%mod;
        if(v.back().first!=0)init=(v.back().first+((v.back().second-1)*ans)%mod)%mod;
        else init=0;
        v.pop_back();
    }
    ans=(ans+init-1)%mod;
    cout<<ans<<endl;
}