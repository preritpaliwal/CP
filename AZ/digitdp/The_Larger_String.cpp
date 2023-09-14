#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
string l;
ll n,dp[100002][3][3];

ll solve(ll nn, ll tl,ll tr){
    if(dp[nn][tl][tr]!=-1)return dp[nn][tl][tr];
    if(nn==n){
        if(tr>1)return dp[nn][tl][tr]=1;
        return dp[nn][tl][tr]=0;
    }
    char lo='A',hi='Z';
    if(tl==1)lo=l[nn];
    ll ans=0;
    for(char c=lo;c<=hi;c++){
        ll ntl=tl,ntr=tr;
        if(c!=lo)ntl=0;
        if(c<l[nn]){
            ntr=0;
        }
        else if(c>l[nn]){
            ntr=2;
        }
        ans+=solve(nn+1,ntl,ntr);
        ans%=mod;
    }
    return dp[nn][tl][tr]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        cin>>l;
        n=l.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<solve(0,1,1)<<endl;
    }
    return 0;
}