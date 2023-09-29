#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    if(n==2){
        cout<<m*(m-1)%mod<<endl;
        return 0;
    }
    if(n==3){
        cout<<((m*(m-1)%mod)*(m-2))%mod<<endl;
        return 0;
    }
    vector<ll> dp[2];
    dp[0].push_back((m*(m-1))%mod);
    dp[1].push_back((dp[0].back()*(m-2))%mod);
    for(int i=0;i<n-3;i++){
        ll tmp=dp[1].back();
        dp[1].push_back(((dp[0].back()*(m-1))%mod + (dp[1].back()*(m-2))%mod)%mod);
        dp[0].push_back(tmp);
    }
    cout<<dp[1].back()<<endl;
}