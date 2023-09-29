#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
string l,r;
ll n,a1,a2,a3;
int dp[20][2][2][2][2][10][10][10][10][10];
ll solve(ll nn,ll ltl,ll ltr,ll rtl,ll rtr,ll ra1,ll ra2,ll ra3,ll tmp1,ll tmp2){
    if(nn==n)return ra1==0 && ra2==0 && ra3==0;
    if(dp[nn][ltl][ltr][rtl][rtr][ra1][ra2][ra3][tmp1][tmp2]!=-1)return dp[nn][ltl][ltr][rtl][rtr][ra1][ra2][ra3][tmp1][tmp2];
    int llo=0,lhi=9,rlo=0,rhi=9;
    if(ltl==1)llo=l[nn]-'0';if(ltr==1)lhi=r[nn]-'0';
    if(rtl==1)rlo=l[nn]-'0';if(rtr==1)rhi=r[nn]-'0';
    ll ans=0;
    for(int i=llo;i<=lhi;i++){
        for(int j=rlo;j<=rhi;j++){
            int nltl=ltl,nltr=ltr,nrtl=rtl,nrtr=rtr,ntmp1=tmp1,ntmp2=tmp2;
            if(i!=llo)nltl=0;if(i!=lhi)nltr=0;
            if(j!=rlo)nrtl=0;if(j!=rhi)nrtr=0;
            ntmp1=(10*tmp1+i)%a3;ntmp2=(10*tmp2+j)%a3;
            ans=(ans + solve(nn+1,nltl,nltr,nrtl,nrtr,(10*ra1+i)%a1,(10*ra2*j)%a2,ntmp1^ntmp2,ntmp1,ntmp2))%mod;
        }
    }
    return dp[nn][ltl][ltr][rtl][rtr][ra1][ra2][ra3][tmp1][tmp2]=ans;
}
int main(){
    ll n1;cin>>n1>>a1>>a2>>a3;
    memset(dp,-1,sizeof(dp));
    r=to_string(n1);
    n=r.size();
    int tmp=n-1;
    while(tmp--)l+='0';
    l+='1';
    cout<<solve(0,1,1,1,1,0,0,0,0,0)<<endl;
    return 0;
}