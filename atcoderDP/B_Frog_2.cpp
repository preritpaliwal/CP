#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio;
    int n,k;cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    vector<long long> dp(n+1,1e9);
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>0){
                dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
            }
            else{
                break;
            }
        }
    }
    cout<<dp[n]<<endl;

}