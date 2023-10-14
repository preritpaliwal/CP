#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> a(n);
    vector<pair<ll,ll>> v(n);
    vector<ll> pre(n+1,0);
    for(ll &i:a)cin>>i;
    for(ll i=0;i<n;i++){v[i].first=a[i];v[i].second=i;}
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){pre[i+1]=pre[i]+v[i].first;
    // cerr<<pre[i+1]<<" ";
    }
    // cerr<<endl;
    ll q;cin>>q;
    while(q--){
        ll c,k;cin>>c>>k;
        ll noItems = upper_bound(pre.begin(),pre.end(),c)-pre.begin()-1;
        ll mostExpItem=v[noItems-1].first;
        ll availMoni=c-pre[noItems];
        // cerr<<"noItems: "<<noItems<< " mostExpItem:" <<mostExpItem<<endl;
        multiset<ll> sm,lr;
        for(int i=0;i<k;i++){
            ll tmp;cin>>tmp;
            // cerr<<"a[tmp-1]"<<a[tmp-1]<<endl;
            if(a[tmp-1]<=mostExpItem)sm.insert(a[tmp-1]);
            else lr.insert(a[tmp-1]);
        }
        ll ans=noItems;
        for(auto &it:sm){
            ans--;
            availMoni+=it;
        }
        // keep buying till you can buy next available
        while(true){
            ll next=0;
            while(true){
                if(noItems>=n){next=-1;break;}
                next=v[noItems++].first;
                if(lr.find(next)==lr.end())break;
            }
            // cerr<<"Next: "<<next<< " AvailMoni: "<<availMoni <<endl;
            if(next==-1)break;
            if(next>availMoni)break;
            availMoni-=next;
            ans++;
        }
        cout<<ans<<" ";
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}