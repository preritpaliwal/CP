#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,c,d;
    cin>>n>>c>>d;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    ll curans = 0;
    if(v[0]!=1){
        curans = c*n + d;
    }
    else{
        curans = c*(n-1);
    }
    ans = curans;
    for(ll i = 0;i<n;i++){
        if(i==0){
            if(v[i]==1){
                continue;
            }
            ll gap = v[i]-2;
            curans = curans-c + d*gap;
            ans = min(ans,curans);
        }
        else{
            if(v[i]==v[i-1]){
                continue;
            }
            else{
                ll gap = v[i]-v[i-1]-1;
                curans = curans-c + d*gap;
                ans = min(ans,curans);
            }
        }
        // cout<<"i,ans"<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}