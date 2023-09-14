#include <bits/stdc++.h>
using namespace std;

string n,m;

vector<vector<int>> dp;

int solve(int k1,int k2){
    if(k1==-1 && k2==-1)return 0;
    if(k1<0)return k2+1;
    if(k2<0)return k1+1;
    if(dp[k1][k2]!=-1)return dp[k1][k2];
    int ans=0;
    if(n[k1]==m[k2])ans=solve(k1-1,k2-1);
    else{
        ans=1+min(min(solve(k1,k2-1),solve(k1-1,k2)),solve(k1-1,k2-1));
    }
    return dp[k1][k2]=ans;

}

int main(){
    cin>>n>>m;
    dp.clear();dp.resize(n.size(),vector<int> (m.size(),-1));
    cout<<solve((int)n.size()-1,(int)m.size()-1)<<endl;
}