#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int h,w,n;cin>>h>>w>>n;vector<pair<int,int>> x(n);
    vector<vector<int>> dp(h,vector<int> (w,1));
    ll ans=h+w-1;
    for(int i=0;i<n;i++){cin>>x[i].first>>x[i].second;dp[x[i].first-1][x[i].second-1]=0;if(x[i].first-1==0 || x[i].second-1==0)ans--;}
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(dp[i][j]!=0)dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            ans+=dp[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}