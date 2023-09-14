#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
#define MAXN 3001

int main(){
    fastio;
    string s,t;
    cin>>s>>t;
    vector<vector<ll>> dp(s.size()+1, vector<ll> (t.size()+1,0));
    for(ll i=1;i<=s.size();i++){
        for(ll j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans;
    ll l=s.size(),r=t.size();
    while(l+r!=0){
        if(l>0 && dp[l][r]==dp[l-1][r]){
            l--;
        }
        else if(r>0 && dp[l][r]==dp[l][r-1]){
            r--;
        }
        else{
            ans+=s[l-1];
            l--;
            r--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}