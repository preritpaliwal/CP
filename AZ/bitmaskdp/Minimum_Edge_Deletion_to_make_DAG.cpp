// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<int> dp;
// vector<vector<int>> adj;

// int solve(int mask){
//     if(__builtin_popcount(mask)==n)return 0;
//     if(dp[mask]!=-1)return dp[mask];
//     int ans=1e9;
//     for(int i=1;i<=n;i++){
//         if(mask&(1<<i))continue;
//         int del=0;
//         for(int j=1;j<=n;j++)if(mask&(1<<j))del+=adj[i][j];
//         cerr<<"call: "<<(mask|(1<<i))<<endl;
//         ans=min(ans,del+solve(mask|(1<<i)));
//         cerr<<"ret: "<<(mask|(1<<i))<<" : "<<solve(mask|1<<i)<<endl;
//     }
//     return dp[mask]=ans;
// }

// int main(){
//     int t=1;cin>>t;
//     while(t--){
//         cin>>n;
//         adj.clear();adj.resize(n+1,vector<int> (n+1,0));
//         dp.clear();dp.resize(1<<(n+1),-1);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 cin>>adj[i][j];
//             }
//         }
//         int ans=1e9;
//         for(int i=1;i<=n;i++){
//             ans=min(ans,solve(1<<i));
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;   //typedef ll long long int;
int n;
int isEdge[17][17];
ll dp[1LL<<17];
ll rec(ll mask){
    int cnt = __builtin_popcount(mask);
    if(cnt == n){
        return 0;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    ll ans = 1e9;
    for(int i=1; i<=n;i++){
        if((mask&(1LL<<i))) continue;
        ll backedges = 0LL;
        for(int j=1; j<=n;j++){
            if(!(mask&(1LL<<j))) continue;
            if(isEdge[i][j]) backedges++;
        }
        cerr<<"call: "<<(mask|(1LL<<i))<<endl;
        ans = min(ans, backedges+rec(mask|(1LL<<i)));
        cerr<<"ret: "<<(mask|(1LL<<i))<<" : "<<rec(mask|(1LL<<i))<<endl;;
    }
    return dp[mask]= ans;
}

void solve(int testcase){
    cin>>n;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            cin>>isEdge[i][j];
        }
    }
    for(int j=0; j<=(1LL<<(n+1)); j++){
            dp[j] =-1;
        }
    ll ans = rec(1LL<<1);
    for(int i=2; i<=n;i++){
        ans = min(ans, 1LL<<i);
    }
    cout<<ans<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    //
        //code for precomputation to be used across all the testcases.

    //

    int testcases=1;
   
    cin>>testcases;
    
   for(int i=1; i<=testcases; i++)
    {solve(i);}
    return 0;
}