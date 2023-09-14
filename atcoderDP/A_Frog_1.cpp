#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio;
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    v[0]=v[1];
    vector<int> dp(n+1,0);
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    }
    cout<<dp[n]<<endl;
}