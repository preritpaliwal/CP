// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;
// int mod=1e9+7;
// ll sum=100,cnt=100;
// vector<vector<vector<ll>>> dp,pre;
// void updatePre(int curi){
//     for(int s=0;s<=sum;s++){
//         for(int d=0;d<=sum;d++){
//             if(d==0){
//                 pre[curi][s][d]=dp[curi][s][d];
//                 continue;
//             }
//             pre[curi][s][d]=(pre[curi][s][d-1]+dp[curi][s][d])%mod;
//         }
//     }
// }
// void updateDp(int curi){
//     for(int s=0;s<=sum;s++){
//         for(int d=0;d<=sum;d++){
//             if(s-d<0)continue;
//             dp[curi][s][d]=pre[curi-1][s-d][d];
//         }
//     }
// }
// void solve(){
//     dp.assign(cnt+1,vector<vector<ll>> (sum+1,vector<ll> (sum+1,0)));
//     pre=dp;
//     dp[0][0][0]=1;
//     updatePre(0);
//     for(int i=1;i<=cnt;i++){
//         updateDp(i);
//         updatePre(i);
//     }
// }   

// int main(){
//     solve();
//     int t;cin>>t;
//     while(t--){
//         ll n,k;cin>>n>>k;cout<<pre[k][n][n]<<"\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
vector<vector<vector<ll>>> dp;
void solve(){
    ll sum=100,cnt=100;
    dp.assign(cnt+1,vector<vector<ll>> (sum+1,vector<ll> (sum+1,0)));
    for(int i=0;i<=sum;i++){
        dp[0][0][i]=1;
    }
    for(int i=1;i<=cnt;i++){
        for(int s=0;s<=sum;s++){
            for(int d=0;d<=sum;d++){
                if(d==0){
                    dp[i][s][d]=dp[i-1][s][d];
                    continue;
                }
                if(s<d){
                    dp[i][s][d]=dp[i][s][d-1];
                    continue;
                }
                dp[i][s][d]=(dp[i-1][s-d][d]+dp[i][s][d-1])%mod;
            }
        }
    }
}   

int main(){
    solve();
    int t;cin>>t;
    while(t--){
        ll sum,cnt;cin>>sum>>cnt;cout<<dp[cnt][sum][sum]<<"\n";
    }
    return 0;
}