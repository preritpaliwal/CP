#include "bits/stdc++.h"
using namespace std;

int solve(int n,int s,vector<vector<int>> &sh){
    vector<vector<int>> dp(n+1,vector<int> (s+1,0));
    for(int i=1;i<=n;i++){
        dp[i][0]=1e9;
    }
    for(int i=1;i<=s;i++){
        deque<pair<int,int>> q;
        q.push_back({dp[i-1][0],0});
        int np=sh[i][0];
        int pc=sh[i][1];
        int dc=sh[i][2];
        for(int j=0;j<=n;j++){
            dp[i][j]=q.front().first+;
            while(j+1>np+q.front().second){
                q.pop_front();
            }
            while()
        }
    }
}

int main() {
    int n,s;
    vector<vector<int>> shops(s,vector<int> (3,0));
    cout<<solve(n,s,shops)<<"\n";
}