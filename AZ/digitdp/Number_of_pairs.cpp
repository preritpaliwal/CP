#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

string s;
ll n,dp[51][2][2][451][451];
vector<bool> prime(901,1);

ll solve(ll nn,ll tl,ll tr,ll ls, ll rs){
    if(nn==n){
        if(ls<rs && prime[ls+rs])return 1;
        return 0;
    }
    if(dp[nn][tl][tr][ls][rs]!=-1)return dp[nn][tl][tr][ls][rs];
    ll ans=0;
    for(ll i=0;i<10;i++){
        ll lo=0,hi=9;
        if(tl==1)lo=i;
        if(tr==1)hi=s[nn]-'0';
        for(ll j=lo;j<=hi;j++){
            ll ntl=tl,ntr=tr,nls=ls,nrs=rs;
            nls+=i;nrs+=j;
            // if(nls>=nrs+9*(n-nn-1))continue;
            if(j!=lo)ntl=0;
            if(j!=hi)ntr=0;
            ans+=solve(nn+1,ntl,ntr,nls,nrs);
            ans%=mod;
        }
    }
    return dp[nn][tl][tr][ls][rs]=ans;
}

int main(){
    prime[0]=prime[1]=0;
    for(int i=2;i<901;i++){
        if(prime[i]){
            for(int j=i*i;j<901;j+=i)prime[j]=0;
        }
    }
    // memset(dp,-1,sizeof(dp));
    cin>>s;
    n=s.size();
    for(int i1=0;i1<=n;i1++)for(int i2=0;i2<2;i2++)for(int i3=0;i3<2;i3++)for(int i4=0;i4<=9*n;i4++)for(int i5=0;i5<=9*n;i5++)dp[i1][i2][i3][i4][i5]=-1;
    cout<<solve(0,1,1,0,0)<<endl;;
}