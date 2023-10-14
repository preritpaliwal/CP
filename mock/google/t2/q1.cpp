#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;vector<ll> a(n);for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll> pre(n,0);
    pre[0]=a[0];
    multiset<ll> p1,p2;
    p1.insert(a[0]);
    for(ll i=1;i<n;i++){
        p2.insert(a[i]);
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    map<ll,vector<ll>> dif1,dif2;
    for(ll i=0;i<n-1;i++){
        ll ls=pre[i],rs=pre[n-1]-pre[i];
        ll dif=rs-ls;
        ans+=(dif==0);
        if(p2.find(dif)!=p2.end()){
            dif1[dif].push_back(i);
        }
        if(p1.find(-dif)!=p1.end()){
            dif2[-dif].push_back(i);
        }
        p1.insert(a[i+1]);
        p2.erase(p2.find(a[i+1]));
    }
    ll maxi=0;
    for(ll i=0;i<n;i++){
        ll sm=lower_bound(dif1[a[i]].begin(),dif1[a[i]].end(),i)-dif1[a[i]].begin();
        ll lr=dif2[a[i]].end() -  lower_bound(dif2[a[i]].begin(),dif2[a[i]].end(),i);
        maxi=max(maxi,sm+lr);
    }
    cout<<max(ans,maxi)<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}