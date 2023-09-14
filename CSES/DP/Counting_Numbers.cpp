#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string l,r;
ll n,dp[20][2][2][2];

ll solve(ll nn,ll tl,ll tr,ll dig){
    if(nn==n)return 1;
    // cerr<<"dig!=10:  "<<(dig!=10)<<endl;
    if(dp[nn][tl][tr][dig!=10]!=-1)return dp[nn][tl][tr][(dig!=10)];
    ll lo=0,hi=9,ans=0 ;
    if(tl==1)lo=l[nn]-'0';if(tr==1)hi=r[nn]-'0';
    for(int i=lo;i<=hi;i++){
        if(dig==i)continue;
        int ntl=tl,ntr=tr,ndig=i;
        if(lo!=i)ntl=0;if(i!=hi)ntr=0;
        if(i==0 && dig==10)ndig=10;
        ans+=solve(nn+1,ntl,ntr,ndig);
    }
    return dp[nn][tl][tr][(dig!=10)]=ans;
}

int main(){
    cin>>l>>r;
    n=r.size();
    memset(dp,-1,sizeof(dp));
    int dif=n-l.size();
    string tmp;
    while(dif--)tmp+='0';
    l=tmp+l;
    cout<<solve(0,1,1,10);
}