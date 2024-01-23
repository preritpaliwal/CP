#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,c;cin>>n>>c;
    vector<ll> sz(n+1,0);for(ll i=1;i<=n;i++)cin>>sz[i];
    vector<pair<ll,ll>> vp(n-1);
    for(int i =2;i<=n;i++){
        vp[i-2].first=sz[i]-c*i;
        vp[i-2].second=i;
    }
    sort(vp.begin(),vp.end());
    for(int i=n-2;i>=0;i--){
        if(sz[1]+vp[i].first>=0){
            sz[1]+=sz[vp[i].second];
        }
        else{
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
        // cerr<<"\n\n";
    }
    return 0;
}