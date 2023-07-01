#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 998244353;
#define MAXN 100001
int fact[MAXN];
int invFact[MAXN];

int getInvFact(int a){
    int pow = mod-2;
    int ans = 1;
    int cur = a;
    while(pow!=0){
        if(pow&1){
            ans= (1LL*ans*cur)%mod;
        }
        cur= (1LL*cur*cur)%mod;
        pow>>=1;
    }
    return ans%mod;
}

int isPrime(int a){
    if(a==1){
        return false;
    }
    for(int i = 2;i*i<=a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    map<int,pair<int,int>> mp;
    for(int i = 0;i<2*n;i++){
        int a;
        cin>>a;
        mp[a].first++;
        mp[a].second = isPrime(a);
    }
    
    int commonFactor = fact[n];
    vector<int> primes;
    for(auto it:mp){
        if(it.second.second){
            primes.push_back(it.second.first);
        }
        else{
            commonFactor = (1LL*commonFactor*invFact[it.second.first])%mod;
        }
    }
    if(primes.size()<n){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(primes.size()+1,vector<int> (n+1,0));
    dp[0][0] = 1;
    for(int i = 1;i<=primes.size();i++){
        dp[i][0] = (1LL*invFact[primes[i-1]]*dp[i-1][0])%mod;
    }
    for(int i = 1;i<n+1;i++){
        dp[0][i] = 0;
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<=primes.size();j++){
            dp[j][i] = ((1LL*invFact[primes[j-1]]*dp[j-1][i]) + (1LL*invFact[primes[j-1]-1]*dp[j-1][i-1]))%mod;
        }
    }
    cout<<(1LL*commonFactor*dp[primes.size()][n])%mod<<endl;
    return ;
}

int main(){
    fact[0] = 1;
    invFact[0] = 1;
    for(int i = 1;i<MAXN;i++){
        fact[i] = (1LL*fact[i-1]*i)%mod;
        invFact[i] = getInvFact(fact[i]);
    }

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}