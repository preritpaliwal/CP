#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;
    vector<ll> dp(1e5+3,1e18);
    dp[0]=0;
    ll tot=0;
    for(ll i=0;i<n;i++){
        ll a,b,c;cin>>a>>b>>c;
        ll flip=(b+1-a)/2;
        if(a>b)flip=0;
        for(int i=dp.size()-1;i>=c;i--){
            dp[i]=min(dp[i],dp[i-c]+flip);
        }
        tot+=c;
    }
    ll ans=1e18;
    for(int i=tot;i*2>tot;i--){
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}