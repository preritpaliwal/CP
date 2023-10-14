#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> dp,a,b,ans;
ll rec(ll idx,ll mask){
    cerr<<idx<<" "<<mask<<endl;
    if(mask==0) return dp[mask]=1;
    if(idx>=n) return dp[mask]=0;
    if(dp[mask]!=-1)return dp[mask];
    ll ans=0;
    for(int i=0;i<m;i++){
        if(mask&(1<<i)){
            ll cnt;
            if(b[i]%a[idx]==0){
                cnt=b[i]/a[idx];
            }
            else{
                cnt=1+b[i]/a[idx];
            }

            ans+=rec(cnt+idx,mask^(1<<i));
        }
    }
    if(ans==0){
        return dp[mask]=0;
    }
    else{
        return dp[mask]=1;
    }
}
void solve(){
    cin>>n>>m;
    a.assign(n,0);for(ll &i:a)cin>>i;
    b.assign(m,0);for(ll &i:b)cin>>i;
    sort(a.begin(),a.end());
    dp.clear();dp.assign(1<<m,-1);
    ans.clear();ans.assign(1<<m,-1);
    cerr<<"h\n";
    if(rec(0,(1<<m)-1)==0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}