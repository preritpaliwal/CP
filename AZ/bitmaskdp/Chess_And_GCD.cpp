#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
vector<ll> v;
vector<ll> dp;

ll hap(ll i,ll j,ll k){
    return k*(abs(v[i]-v[j]))*(__gcd(v[i],v[j]));
}

ll solve(ll k,ll mask){
    if(mask+1==1<<(2*n))return 0;
    if(dp[mask]!=-1)return dp[mask];
    ll ans=0;
    for(ll i=0;i<2*n;i++){
        if(mask&(1<<i))continue;
        for(ll j=i+1;j<2*n;j++){
            if(mask&(1<<j) || j==i)continue;
            ans=max(ans,hap(i,j,k)+solve(k-1,mask|(1<<i)|(1<<j)));
        }
    }
    return dp[mask]=ans;
}

int main(){
    ll t=1;cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        v.resize(2*n);
        dp.clear();
        dp.resize(1<<(2*n),-1);
        for(ll &i:v)cin>>i;
        cout<<solve(n,0)<<endl;
    }
    return 0;
}