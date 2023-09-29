#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;vector<ll> c(n);for(ll i=0;i<n;i++)cin>>c[i];
    ll k;cin>>k;
    vector<pair<ll,ll>> arr;
    ll last=1e9+7;
    for(ll i=n-1;i>=0;i--){
        if(c[i]<last){
            arr.push_back({c[i],i});
            last=c[i];
        }
    }
    reverse(arr.begin(),arr.end());
    vector<ll> ans(n,0);
    ll pur=k/last;
    ll rem=k%last;
    ans[0]+=pur;
    ll idx=arr[0].second;
    if(idx!=n-1){
        ans[idx+1]-=pur;
    }
    for(ll i=1;i<arr.size();i++){
        ll dif=arr[i].first-last;
        if(rem<dif)break;
        ll pur1=rem/dif;
        pur1=min(pur,pur1);
        rem=(pur1*last+rem)%arr[i].first;
        if(idx!=n-1){
            ans[idx+1]+=pur1;
            last=arr[i].first;
            idx=arr[i].second;
            pur=pur1;
        }
        if(idx+1!=n){
            ans[idx+1]-=pur1;
        }
    }
    cout<<ans[0]<<" ";
    for(ll i=1;i<n;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}