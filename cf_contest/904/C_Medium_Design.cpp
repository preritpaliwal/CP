#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll cnt1=0,cntm=0,cntcur=0,ans=0;
    multiset<pair<ll,ll>> ms;
    for(ll i=0;i<n;i++){
        while(!ms.empty()){
            if(ms.begin()->first<v[i].first){
                if(v[ms.begin()->second].first==1){
                    cnt1--;
                }
                ms.erase(ms.begin());
            }
            else{
                break;
            }
        }
        ms.insert({v[i].second,i});
        if(v[i].second==m)cntm++;
        if(v[i].first==1)cnt1++;
        cntcur=ms.size();
        ans=max(ans,cntcur-min(cnt1,cntm));
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}