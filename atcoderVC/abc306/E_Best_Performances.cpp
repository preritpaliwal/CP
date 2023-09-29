#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,k,q;cin>>n>>k>>q;
    vector<ll> v(n+1,0);
    multiset<pair<ll,ll>> topk,other;
    set<ll> itopk;
    for(int i=1;i<=n;i++){
        if(i<=k){
            itopk.insert(i);
            topk.insert({0,i});
        }
        else{
            other.insert({0,i});
        }
    }
    ll ans=0;
    for(ll i=0;i<q;i++){
        ll x,y;cin>>x>>y;
        ll old=v[x];
        v[x]=y;
        if(itopk.find(x)==itopk.end()){
            if((*(topk.begin())).first>=y){
                other.erase(other.find({old,x}));
                other.insert({y,x});
            }
            else{
                other.erase(other.find({old,x}));
                auto p=*(topk.begin());
                topk.erase(topk.begin());
                topk.insert({y,x});
                other.insert(p);
                itopk.erase(p.second);
                itopk.insert(x);
                ans+=(y-p.first);
            }
        }
        else{
            if(!other.empty() && (*(other.rbegin())).first>=y){
                topk.erase(topk.find({old,x}));
                auto p=*(other.rbegin());
                other.erase(other.find(p));
                other.insert({y,x});
                topk.insert(p);
                itopk.insert(p.second);
                itopk.erase(x);
                ans+=(p.first-old);
            }
            else{
                topk.erase(topk.find({old,x}));
                topk.insert({y,x});
                ans+=(y-old);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}