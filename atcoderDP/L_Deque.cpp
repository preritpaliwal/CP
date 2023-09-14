#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;vector<ll> v(n);for(auto &i:v)cin>>i;
    vector<vector<ll>> dp(n,vector<ll> (n,0));
    for(int i=0;i<n;i++)dp[i][i]=v[i];
    for(int r=1;r<n;r++)for(int l=0;l<n-r;l++)dp[l][r+l]=max(v[l]-dp[l+1][r+l],v[l+r]-dp[l][r+l-1]);
    cout<<dp[0][n-1]<<endl;
}