#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    vector<pair<ll,ll>> segs;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].second>=v[j].first){
                segs.push_back({v[i].first,max(v[j].second,v[i].second)});
            }
        }
    }
    sort(segs.begin(),segs.end());
    vector<ll> dp(segs.size()+1,0);
    
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