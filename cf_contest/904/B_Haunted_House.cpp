#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;string s;cin>>s;
    ll zero=n-1;
    vector<ll> dp(n,0);
    for(ll i=0;i<n;i++){
        while(zero>=0 && s[zero]!='0'){
            zero--;
        }
        if(zero==-1){
            while(i<n){
                dp[i]=-1;
                cout<<dp[i++]<<" ";
            }
            break;
        }
        if(i!=0) dp[i]=n-1-i-zero+dp[i-1];
        else dp[i]=n-1-zero;
        zero--;
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    return;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}