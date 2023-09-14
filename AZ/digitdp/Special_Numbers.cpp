#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string l,r;
ll k,n,dp[20][2][2][3][3][5][7][9][2][2][2][2];

ll solve(ll nn,ll tl,ll tr,ll pos,ll sum3,ll sum5,ll sum7,ll sum9,ll pre3,ll pre5,ll pre7,ll pre9){
    if(nn==n){
        ll ret=1;
        if(pre3==1 && sum3==0)ret=0;
        if(pre5==1 && sum5==0)ret=0;
        if(pre7==1 && sum7==0)ret=0;
        if(pre9==1 && sum9==0)ret=0;
        return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9][pre3][pre5][pre7][pre9] = ret;
    }
    if(dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9][pre3][pre5][pre7][pre9]!=-1)return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9][pre3][pre5][pre7][pre9];
    ll lo=0,hi=9;
    if(tl==1)lo=l[nn]-'0';
    if(tr==1)hi=r[nn]-'0';
    ll ans=0;
    for(ll i=lo;i<=hi;i++){
        // cerr<<"i="<<i<<endl;
        if(i==1)continue;
        ll ntl=tl,ntr=tr,npos=pos,nsum3=sum3,nsum5=sum5,nsum7=sum7,nsum9=sum9,npre3=pre3,npre5=pre5,npre7=pre7,npre9=pre9;
        if(pos==1)if(i%2==0)continue;
        if(pos==0){
            if(i!=0 && i%2==0)continue;
            if(i!=0)npos=1;
        }
        if(i!=lo)ntl=0;if(i!=hi)ntr=0;
        nsum3=(10*nsum3+i)%3;
        nsum5=(10*nsum5+i)%5;
        nsum7=(10*nsum7+i)%7;
        nsum9=(10*nsum9+i)%9;
        if(i==3)npre3=1;
        if(i==5)npre5=1;
        if(i==7)npre7=1;
        if(i==9)npre9=1;
        // cerr<<"call: "<<"nn="<<nn+1<<", ntl="<<ntl<<", ntr="<<ntr<<", npos="<<npos<<", nsum3="<<nsum3<<", nsum5="<<nsum5<<", nsum7="<<nsum7<<", nsum9="<<nsum9<<", npre3="<<npre3<<", npre5="<<npre5<<", npre7="<<npre7<<", npre9="<<npre9<<endl;
        ans+=solve(nn+1,ntl,ntr,npos,nsum3,nsum5,nsum7,nsum9,npre3,npre5,npre7,npre9);
        // cerr<<"ret: "<<"nn="<<nn+1<<", ntl="<<ntl<<", ntr="<<ntr<<", npos="<<npos<<", nsum3="<<nsum3<<", nsum5="<<nsum5<<", nsum7="<<nsum7<<", nsum9="<<nsum9<<", npre3="<<npre3<<", npre5="<<npre5<<", npre7="<<npre7<<", npre9="<<npre9<<":  "<<dp[nn+1][ntl][ntr][npos][nsum3][nsum5][nsum7][nsum9][npre3][npre5][npre7][npre9]<<endl;
    }
    return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9][pre3][pre5][pre7][pre9]=ans;
}

string getno(ll nn,ll tl,ll tr,ll pos,ll sum3,ll sum5,ll sum7,ll sum9,ll pre3,ll pre5,ll pre7,ll pre9){
    if(nn==n){
        return "";
    }
    // if(nn==n)return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9] = (sum3==0)&&(sum5==0)&&(sum7==0)&&(sum9==0);
    // if(dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9]!=-1)return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9];
    ll lo=0,hi=9;
    if(tl==1)lo=l[nn]-'0';
    if(tr==1)hi=r[nn]-'0';
    ll ans=0,prev=0;
    for(ll i=lo;i<=hi;i++){
        if(i==1)continue;
        ll ntl=tl,ntr=tr,npos=pos,nsum3=sum3,nsum5=sum5,nsum7=sum7,nsum9=sum9,npre3=pre3,npre5=pre5,npre7=pre7,npre9=pre9;
        if(pos==1)if(i%2==0)continue;
        if(pos==0){
            if(i!=0 && i%2==0)continue;
            if(i!=0)npos=1;
        }
        if(i!=lo)ntl=0;if(i!=hi)ntr=0;
        nsum3=(10*nsum3+i)%3;
        nsum5=(10*nsum5+i)%5;
        nsum7=(10*nsum7+i)%7;
        nsum9=(10*nsum9+i)%9;
        if(i==3)npre3=1;
        if(i==5)npre5=1;
        if(i==7)npre7=1;
        if(i==9)npre9=1;
        ans+=solve(nn+1,ntl,ntr,npos,nsum3,nsum5,nsum7,nsum9,npre3,npre5,npre7,npre9);
        // cerr<<nn<<" "<<i<<" "<<ans<<" "<<k<<endl;
        if(ans>=k){
            k-=prev;
            char c='0'+i;
            return c+getno(nn+1,ntl,ntr,npos,nsum3,nsum5,nsum7,nsum9,npre3,npre5,npre7,npre9);
        }
        prev=ans;
    }
    return "";
    // return dp[nn][tl][tr][pos][sum3][sum5][sum7][sum9]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>l>>r>>k;
        n=r.size();
        ll dif=n-l.size();
        string tmp;
        while(dif--)tmp+='0';
        l=tmp+l;
        // cerr<<l<<" "<<r<<endl;
        ll ans=solve(0,1,1,0,0,0,0,0,0,0,0,0);
        // cerr<<ans<<endl;
        if(ans<k){cout<<-1<<endl;continue;;}
// 		find that number
        cout<<stoll(getno(0,1,1,0,0,0,0,0,0,0,0,0))<<endl;
    }
    return 0;
}