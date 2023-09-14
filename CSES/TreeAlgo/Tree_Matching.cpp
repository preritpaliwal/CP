#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> dp[2];

void maxMatching(int nn,int pp){
    dp[0][nn] = 0;
    dp[1][nn] = 0;

    for(int u:adj[nn]){
        if(u!=pp){
            maxMatching(u,nn);
            dp[0][nn] += dp[1][u];
        }
    }
    for(int u:adj[nn]){
        if(u!=pp){
            dp[1][nn] = max(dp[1][nn],1+dp[0][u]+dp[0][nn] - dp[1][u]);
        }
    }
}


int main(){
    cin>>n;
    adj.clear();
    adj.resize(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp[0].resize(n+1,0);
    dp[1].resize(n+1,0);
    maxMatching(1,0);
    cout<<dp[1][1]<<endl;
}