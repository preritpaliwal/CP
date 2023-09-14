#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<double> p(n);for(auto &i:p)cin>>i;
    vector<double> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            dp[j]=dp[j-1]*p[i]+dp[j]*(1-p[i]);
        }
        dp[0]=dp[0]*(1-p[i]);
    }
    double ans=0;
    for(int i=(n+1)/2;i<=n;i++)ans+=dp[i];
    cout<<setprecision(10)<<ans<<endl;
}