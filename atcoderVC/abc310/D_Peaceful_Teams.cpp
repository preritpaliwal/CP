#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,t,m;
vector<pair<int,int>> p;
vector<vector<int>> dp;

int check(int mask){
    for(auto pp:p){
        if(mask&(1<<pp.first) && (mask)&(1<<pp.second)){
            return 0;
        }
    }
    return 1;
}

int solve(int mask,int t){
    if(dp[t][mask]!=-1)return dp[t][mask];
    if(mask==0)return dp[t][mask]=(t==0);
    if(t==0)return dp[t][mask]=0;
    int ans=check(mask)*(t==1);
    int tmpmask=(mask-1)&mask;
    int here=tmpmask^mask;
    for(int submask=tmpmask;submask>0;submask=(submask-1)&tmpmask){
        ans+=solve(submask,t-1)*check((tmpmask^submask)|here);
    }
    return dp[t][mask]=ans;
}

int main(){
    cin>>n>>t>>m;
    dp.resize(t+1,vector<int> (1<<n,-1));
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;p.push_back({a-1,b-1});
    }
    cout<<solve((1<<n)-1, t)<<endl;
    return 0;
}