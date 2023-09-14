#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

int main(){
    ll n,x;cin>>n>>x;
    vector<int> h(n,0),s(n,0);
    for(int &i:h)cin>>i;
    for(int &i:s)cin>>i;
    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int j=x;j>=h[i];j--){
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    cout<<dp[x]<<endl;
}