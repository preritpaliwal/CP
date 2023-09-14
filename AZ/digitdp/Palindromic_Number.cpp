#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string l,r;
ll n, dp[20][2][2][2][2][2][2];

ll solve(ll nn,ll tl,ll tr,ll ep,ll op, ll prev,ll pprev, ll pos, ll attn){
    if(nn==n){
        dp[nn][tl][tr][ep][op][pos][attn]=ep&op&(~tl);
        // if(dp[nn][tl][tr][ep][op][pos][]==1){
        //     for(int i=0;i<v.size();i++)cerr<<v[i];
        //     cerr<<endl;
        // }
        return dp[nn][tl][tr][ep][op][pos][attn];
    }
    if(dp[nn][tl][tr][ep][op][pos][attn]!=-1){
        // if(dp[nn][tl][tr][ep][op][pos]>0)cerr<<nn<<": dp "<<dp[nn][tl][tr][ep][op][pos]<<endl;
        return dp[nn][tl][tr][ep][op][pos][attn];}
    ll lo=0,hi=9,ans=0;
    if(tl==1)lo=l[nn]-'0';
    if(tr==1)hi=r[nn]-'0';
    for(ll i=lo;i<=hi;i++){
        ll ntl=tl,ntr=tr,nep=ep,nop=op,npos=pos,nprev=i,npprev=prev, nattn=attn;
        // vector<ll> nv=v;
        if(i!=lo)ntl=0;if(i!=hi)ntr=0;
        if(prev==i && pos!=0)nep=1;
        if(pprev==i && pos!=0)nop=1;
        if(pos==0){
            npprev=10;
            nprev=10;
            if(i!=0){
                npos=1;
                nprev=i;
            }
        }
        if(pos==1)nattn=1;
        // cerr<<"call: "<<nn+1<<" "<<ntl<<" "<<ntr<<" "<<nep<<" "<<nop<<" "<<nprev<<" "<<npprev<<" "<<npos<<endl;
        ans+=solve(nn+1,ntl,ntr,nep,nop,nprev,npprev,npos,nattn);
        // cerr<<"ret: "<<nn+1<<" "<<ntl<<" "<<ntr<<" "<<nep<<" "<<nop<<" "<<nprev<<" "<<npprev<<" "<<npos<<": "<<dp[nn+1][ntl][ntr][nep][nop][nprev][npprev][npos]<<endl;
    }
    return dp[nn][tl][tr][ep][op][pos][attn]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
    	memset(dp,-1,sizeof(dp));
        cin>>l>>r;
        n=r.size();
        int dif=n-l.size();
        string tmp;
        while(dif--)tmp+='0';
        l=tmp+l;
        // cerr<<l<<" "<<r<<endl; 
        cout<<solve(0,1,1,0,0,10,10,0,0)<<endl;
        // cerr<<"---------------\n\n\n";
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;

// string l,r;
// ll n, dp[20][2][2][2][2][11][11][2];

// ll solve(ll nn,ll tl,ll tr,ll ep,ll op, ll prev,ll pprev, ll pos){
//     if(nn==n)return dp[nn][tl][tr][ep][op][prev][pprev][pos]=ep&op&(~tl);
//     if(dp[nn][tl][tr][ep][op][prev][pprev][pos]!=-1)return dp[nn][tl][tr][ep][op][prev][pprev][pos];
//     ll lo=0,hi=9,ans=0;
//     if(tl==1)lo=l[nn]-'0';
//     if(tr==1)hi=r[nn]-'0';
//     for(ll i=lo;i<=hi;i++){
//         ll ntl=tl,ntr=tr,nep=ep,nop=op,npos=pos,nprev=i,npprev=prev;
//         if(i!=lo)ntl=0;if(i!=hi)ntr=0;
//         if(prev==i && pos!=0)nep=1;
//         if(pprev==i && pos!=0)nop=1;
//         if(pos==0){
//             npprev=10;
//             nprev=10;
//             if(i!=0){
//                 npos=1;
//                 nprev=i;
//             }
//         }
//         // cerr<<"call: "<<nn+1<<" "<<ntl<<" "<<ntr<<" "<<nep<<" "<<nop<<" "<<nprev<<" "<<npprev<<" "<<npos<<endl;
//         ans+=solve(nn+1,ntl,ntr,nep,nop,nprev,npprev,npos);
//         // cerr<<"ret: "<<nn+1<<" "<<ntl<<" "<<ntr<<" "<<nep<<" "<<nop<<" "<<nprev<<" "<<npprev<<" "<<npos<<": "<<dp[nn+1][ntl][ntr][nep][nop][nprev][npprev][npos]<<endl;
//     }
//     return dp[nn][tl][tr][ep][op][prev][pprev][pos]=ans;
// }

// int main(){
//     int t=1;cin>>t;
//     while(t--){
//     	memset(dp,-1,sizeof(dp));
//         cin>>l>>r;
//         n=r.size();
//         int dif=n-l.size();
//         string tmp;
//         while(dif--)tmp+='0';
//         l=tmp+l;
//         // cerr<<l<<" "<<r<<endl; 
//         cout<<solve(0,1,1,0,0,10,10,0)<<endl;;
//     }
// }