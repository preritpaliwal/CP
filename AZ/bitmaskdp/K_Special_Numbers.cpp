#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string l,r;
int k,n;
ll dp[19][2][2][4][7][8][9][1<<9];

ll solve(ll nn,ll tl,ll tr,ll sum2,ll sum4,ll sum5,ll sum7,ll sum8,ll sum9,ll mask){
    // cerr<<nn<<" "<<tl<<" "<<tr<<" "<<sum2<<" "<<sum4<<" "<<sum5<<" "<<sum7<<" "<<sum8<<" "<<sum9<<" "<<mask<<endl;
    if(nn==n){
        int div=mask&1;
        if(mask&1<<1)div+=sum2==0;
        if(mask&1<<2)div+=(sum9%3)==0;
        if(mask&1<<3)div+=sum4==0;
        if(mask&1<<4)div+=sum5==0;
        if(mask&1<<5)div+=(sum2==0 && (sum9%3)==0);
        if(mask&1<<6)div+=sum7==0;
        if(mask&1<<7)div+=sum8==0;
        if(mask&1<<8)div+=sum9==0;
        return div>=k;
    }
    if(dp[nn][tl][tr][sum4][sum7][sum8][sum9][mask]!=-1)return dp[nn][tl][tr][sum4][sum7][sum8][sum9][mask];
    int lo=0,hi=9;
    if(tl==1)lo=l[nn]-'0';
    if(tr==1)hi=r[nn]-'0';
    ll ans=0;
    for(int i=lo;i<=hi;i++){
        int ntl=tl,ntr=tr,nmask=mask;
        if(i!=lo)ntl=0;if(i!=hi)ntr=0;if(i>0)nmask=mask|(1<<(i-1));
        ans+=solve(nn+1,ntl,ntr,i%2,(10*sum4+i)%4,i%5,(10*sum7+i)%7,(10*sum8+i)%8,(10*sum9+i)%9,nmask);
        // cerr<<ans<<endl;
    }
    return dp[nn][tl][tr][sum4][sum7][sum8][sum9][mask]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>k>>l>>r;
        n=r.size();
        string tmp;
        int dif=n-l.size();
        while(dif--)tmp+='0';
        l=tmp+l;
        // cerr<<"here\n"<<l<<" "<<r<<endl;
        cout<<solve(0,1,1,0,0,0,0,0,0,0)<<endl;
    }
}