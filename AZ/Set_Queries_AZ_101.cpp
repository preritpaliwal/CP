#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll t;cin>>t;
    while(t--){
        set<pair<ll,ll>> s;
        s.insert({0,LLONG_MAX});
        ll q;cin>>q;
        while(q--){
            ll a,b;cin>>a>>b;
            if(a==1){
                auto it=s.upper_bound({b,LLONG_MAX});
                it--;
                ll l=it->first,r=it->second;
                if(r<b)continue;
                if(l<=b-1)s.insert({it->first,b-1});
                if(b+1<=r)s.insert({b+1,it->second});
                s.erase(it);
            }
            else{
                auto it=s.upper_bound({b,LLONG_MAX});
                it--;
                if(b<=it->second)cout<<b<<endl;
                else {
                    it++;cout<<it->first<<endl;
                }
            }
        }
    }
}