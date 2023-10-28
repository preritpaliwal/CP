#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;vector<ll> v(n);map<ll,ll> mp;for(int i=0;i<n;i++){cin>>v[i];mp[v[i]]++;}
    set<ll> l;
    ll ans=0;
    for(int i=0;i<n;i++){
        mp[v[i]]--;
        l.insert(v[i]);
        if(mp[v[i]]==0){
            ans+=l.size();
        }
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}