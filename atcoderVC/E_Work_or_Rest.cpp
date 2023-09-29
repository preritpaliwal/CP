#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;vector<ll> a(n);for(auto &i:a)cin>>i;
    vector<ll> p(n+1,0);
    for(int i=2;i<=n;i+=2){
        p[i]=a[i/2 -1]+p[i-1];
        if(i!=n)p[i+1]=2*a[i/2 -1]+p[i-1];
    }
    vector<ll> dp(n+1,0);
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j],p[i]+dp[j-i]);
        }
    }
    cout<<dp[n];
}