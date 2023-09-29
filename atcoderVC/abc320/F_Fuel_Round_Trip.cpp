#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// wrong
int main(){
    int n,h;cin>>n>>h;vector<int> x(n+1,0);for(int i=1;i<=n;i++)cin>>x[i];vector<pair<int,int>> pf(n);for(int i=1;i<n;i++)cin>>pf[i].first>>pf[i].second;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>> (h+1,vector<ll> (h+1,1e9)));
    for(int i=0;i<=h;i++)for(int j=0;j<=h;j++)dp[0][i][j]=0;
    for(int i=1;i<=n;i++){
        int dis=x[i]-x[i-1];
        for(int j=0;j<=h;j++){
            for(int k=0;k<=h;k++){
                if(k-dis<0 || j+dis>h)continue;
                dp[i][j][k]=dp[i-1][j+dis][k-dis];
            }
        }
        for(int j=0;j<=h;j++){
            for(int k=0;k<=h;k++){
                // dp[i][min(h,j+pf[i].second)][k]=min(dp[i][min(h,j+pf[i].second)][k],pf[i].first+dp[i][j][k]);
                // dp[i][j][min(h,k+pf[i].second)]=min(dp[i][j][min(h,k+pf[i].second)],pf[i].first+dp[i][j][k]);
                dp[i][j][k]=min(dp[i][j][k],dp[i][max(0,j-pf[i].second)][k]+pf[i].first);
                dp[i][j][k]=min(dp[i][j][k],dp[i][j][max(0,k-pf[i].second)]+pf[i].first);
            }
        }

        for(int j=0;j<=h;j++){
            for(int k=0;k<=h;k++){
                cerr<<dp[i][j][k]<<" ";
            }
            cerr<<endl;
        }
        cerr<<"\n\n\n";
    }
    ll ans=1e9;
    for(int i=0;i<=h;i++)for(int j=0;j<=h;j++)ans=min(ans,dp[n][i][j]);
    cout<<((ans>=1e9)?-1:ans)<<endl;
    return  0;
    
}