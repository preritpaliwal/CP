#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    if(n/10 == 0){cout<<1<<endl;return 0;}
    vector<int> dp(n+1,1e9);
    for(int i=1;i<10;i++)dp[i]=1;
    dp[0]=0;
    for(int i=10;i<=n;i++){
        int no=i;
        while(no!=0){
            int dig=no%10;
            dp[i]=min(dp[i],1+dp[i-dig]);
            no/=10;
        }
    }
    cout<<dp[n]<<endl;
}