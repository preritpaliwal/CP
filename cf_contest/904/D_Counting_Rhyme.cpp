#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;
    vector<ll> v(n),cnt(n+1,0),dp(n+1,0),div(n+1,0);
    for(int i=0;i<n;i++){cin>>v[i];cnt[v[i]]++;}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            div[i]+=cnt[j];
        }
    }
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j+=i){
            dp[i]-=dp[j];
        }
        dp[i] += (div[i]*(div[i]-1))/2;
    }
    vector<int> present(n+1,0);
    for(int i=1;i<=n;i++){
        if(cnt[i]>0){
            for(int j=i;j<=n;j+=i){
                present[j]++;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(present[i]==0)ans+=dp[i];
    }
    cout<<ans<<"\n";
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}