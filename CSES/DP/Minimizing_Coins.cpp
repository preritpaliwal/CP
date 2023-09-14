#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(int &i:v)cin>>i;
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for(int c:v){
        for(int i=c;i<=x;i++){
            dp[i]=min(dp[i],1+dp[i-c]);
        }
    }
    cout<<(dp[x]>=1e9?-1:dp[x])<<endl;
}