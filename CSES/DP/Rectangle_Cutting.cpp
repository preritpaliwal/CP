#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int a,int b){
    if(a>b)swap(a,b);
    if(a==b)return dp[a][b]=0;
    if(dp[a][b]!=-1)return dp[a][b];
    if(a==1 || b==1)return dp[a][b]=max(a,b)-1;
    int ans=1e9;
    for(int i=1;i<a;i++){
        ans=min(ans,1+solve(i,b)+solve(a-i,b));
    }
    for(int i=1;i<b;i++){
        ans=min(ans,1+solve(a,i)+solve(a,b-i));
    }
    return dp[a][b]=ans;
}

int main(){
    int a,b;cin>>a>>b;
    if(a>b)swap(a,b);    
    dp.resize(a+1,vector<int> (b+1,-1));
    cout<<solve(a,b)<<endl;
}