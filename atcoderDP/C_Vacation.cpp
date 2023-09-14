#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio;
    int n;cin>>n;
    vector<vector<int>> a(n+1,vector<int> (3,0));
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    vector<vector<long long>> dp(n+1,vector<long long> (3,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                }
            }
        }
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}