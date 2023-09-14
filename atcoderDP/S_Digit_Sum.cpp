// #include <bits/stdc++.h>
// using namespace std;
// int mod=1e9+7;
// using ll=long long;
// string l,r;
// int d,n,dp[10002][2][2][101];

// ll solve(int nn,int tl,int tr,int sum){
//     if(nn==n)return sum==0;
//     if(dp[nn][tl][tr][sum]!=-1)return dp[nn][tl][tr][sum];
//     int lo=0,hi=9;if(tl==1)lo=l[nn]-'0';if(tr==1)hi=r[nn]-'0';
//     ll ans=0;
//     for(int i=lo;i<=hi;i++){
//         int ntl=tl,ntr=tr,nsum=sum;
//         if(lo!=i)ntl=0;if(hi!=i)ntr=0;
//         nsum=(sum+i)%d;
//         ans=(ans+solve(nn+1,ntl,ntr,nsum))%mod;
//     }
//     return dp[nn][tl][tr][sum]=ans;
// }

// int main(){
//     cin>>r>>d;
//     n=r.size();
//     for(int i=1;i<n;i++)l+='0';
//     l+='1';
//     memset(dp,-1,sizeof(dp));
//     cout<<solve(0,1,1,0)<<endl;
// }
#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
using ll=long long;
string r;
int d,n,dp[10002][2][101];

ll solve(int nn,int tr,int sum){
    if(nn==n)return sum==0;
    if(dp[nn][tr][sum]!=-1)return dp[nn][tr][sum];
    int hi=9;if(tr==1)hi=r[nn]-'0';
    ll ans=0;
    for(int i=0;i<=hi;i++){
        int ntr=tr,nsum=sum;
        if(hi!=i)ntr=0;
        nsum=(sum+i)%d;
        ans=(ans+solve(nn+1,ntr,nsum))%mod;
    }
    return dp[nn][tr][sum]=ans;
}

int main(){
    cin>>r>>d;
    n=r.size();
    memset(dp,-1,sizeof(dp));
    cout<<(solve(0,1,0)+mod-1)%mod<<endl;
}