#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        mp[a]++;
    }
    if(mp.size()<3){
        if(mp.size()==1){
            cout<<"Yes\n";
        }
        else{
            auto it=mp.begin();
            ll dif=it->second;
            it++;
            dif = dif-it->second;
            if(abs(dif)<=1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    else{
        cout<<"No\n";
    }
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