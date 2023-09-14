#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll l,r, dp[64][2][2][2][2];

ll solve(ll nn,ll ltl,ll ltr,ll rtl, ll rtr){
    if(nn==-1)return 0;
    if(dp[nn][ltl][ltr][rtl][rtr]!=-1)return dp[nn][ltl][ltr][rtl][rtr];
    int llo=0,lhi=1,rlo=0,rhi=1;
    // cerr<<"l,r: "<<l<<" "<<r<<endl;
    if(ltl==1)llo=(l&(1LL<<nn)?1:0);
    if(ltr==1)lhi=(r&(1LL<<nn)?1:0);
    if(rtl==1)rlo=(l&(1LL<<nn)?1:0);
    if(rtr==1)rhi=(r&(1LL<<nn)?1:0);
    ll ans=0;
    if(llo==rlo && rlo==lhi && rlo==rhi){
        ans=solve(nn-1,ltl,ltr,rtl,rtr);
        return dp[nn][ltl][ltr][rtl][rtr]=ans;
    }
    // cerr<<nn<<" "<<ltl<<" "<<ltr<<", "<<rtl<<" "<<rtr<<": "<<llo<<" "<<lhi<<", "<<rlo<<" "<<rhi<<endl;
    for(int li=llo;li<=lhi;li++){
        for(int ri=rlo;ri<=rhi;ri++){
            if(li==ri)continue;
            ll nltl=ltl,nltr=ltr,nrtl=rtl,nrtr=rtr;
            if(llo!=li)nltl=0;
            if(rlo!=ri)nrtl=0;
            if(lhi!=li)nltr=0;
            if(rhi!=ri)nrtr=0;
            ans=max(solve(nn-1,nltl,nltr,nrtl,nrtr),ans);
        }
    }
    // cerr<<"ans: "<<ans<<endl;
    ans+=1LL<<nn;
    // cerr<<"ans: "<<ans<<endl;
    return dp[nn][ltl][ltr][rtl][rtr]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>l>>r;
        cout<<solve(63,1,1,1,1)<<endl;
        // cerr<<" ---------------------- \n\n\n\n\n";
    }
    return 0;
}