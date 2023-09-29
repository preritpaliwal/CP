#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
vector<vector<ll>> dp;
string s;
int main(){
    cin>>s;
    ll n=s.size();
    dp.resize(n+1,vector<ll> (n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j-1];
            }
        }
        else if(s[i-1]==')'){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j+1];
            }
        }
        else{
            for(int j=0;j<=n;j++){
                if(j!=0){
                    dp[i][j]=dp[i-1][j-1];
                }
                if(j!=n){
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                }
            }
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}