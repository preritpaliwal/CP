#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
vector<vector<vector<ll>>> dp,pre;

void solve(){
    ll n,m,c0;cin>>n>>m>>c0;
    cout<<pre[n][m][c0]<<endl;
}

int main(){
    dp.assign(101, vector<vector<ll>> (101,vector<ll> (101, 0)));
    dp[0][0][0]=1;
    pre=dp;
    for(int c=0;c<=100;c++){
        for(int p=1;p<=100;p++){
            pre[0][p][c]=(pre[0][p-1][c]+dp[0][p][c])%mod;
        }
    }
    for(int i=1;i<=100;i++){
        for(int p=0;p<=100;p++){
            for(int c=0;c<=100;c++){
                if(p==0 || c==0){dp[i][p][c]=0;continue;}
                dp[i][p][c]=(pre[i-1][p-1][c-1]+(dp[i-1][p][c]*(p))%mod)%mod;
            }
        }
        for(int c=0;c<=100;c++){
            for(int p=0;p<=100;p++){
                if(p==0){pre[0][p][c]=dp[0][p][c];continue;}
                pre[i][p][c]=(pre[i][p-1][c]+dp[i][p][c])%mod;
            }
        }
    }
    
    int t;cin>>t;
    while(t--)solve();
    return 0;
}