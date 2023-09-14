#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

int main(){

    ll n;cin>>n;
    if((n*(n+1)/2)%2==1){cout<<0<<endl;return 0;}
    vector<ll> dp((n*(n+1)/4) + 1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n*(n+1)/4;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    if(dp.back()%2==0){
        cout<<dp.back()/2<<endl;
    }
    else{
        cout<<(dp.back()+mod)/2<<endl;
    }
    return 0;
}