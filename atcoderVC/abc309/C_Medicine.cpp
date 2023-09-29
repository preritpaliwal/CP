#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,k;cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    ll day1=0;
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        day1+=v[i].second;
    }   
    sort(v.begin(),v.end());
    ll cur=1;
    ll ans=-1;
    ll idx=0;
    while(true){
        if(day1<=k){
            ans=cur;
            break;
        }
        cur=v[idx].first+1;
        while(cur>v[idx].first){
            day1-=v[idx].second;
            idx++;
            if(idx==n){
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}