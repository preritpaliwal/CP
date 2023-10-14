
// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;
// ll n;
// vector<ll> v,dp;
// map<ll,ll> mp;
// ll solvedp(ll mex){
//     if(dp[mex]!=-1)return dp[mex];
//     ll ans=1e9;
//     for(auto &p:mp){
//         if(p.first>=mex)break;
//         ans=min(ans,(p.second-1)*mex + p.first+ solvedp(p.first));
//     }
//     return dp[mex]=ans;
// }
// void solve(){
//     cin>>n;
//     v.clear();v.resize(n);
//     mp.clear();
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         mp[v[i]]++;
//     }
//     sort(v.begin(),v.end());
//     dp.clear();dp.resize(n+2,-1);
//     dp[0]=0;
//     ll mex=0;
//     for(int i=0;i<n;i++){
//         if(v[i]>mex)break;
//         else if(v[i]==mex)mex++;
//     }
//     cout<<solvedp(mex)<<endl;;
//     return;
// }

// int main(){
//     int t=1;
//     cin>>t;
//     while(t--)solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxlen=1e6+3;
ll prime[maxlen];
vector<ll> pr;
int main(){
    ll t;cin>>t;
    prime[0]=prime[1]=1;
    for(ll i=2;i<maxlen;i++){
        if(prime[i]==0){
            prime[i]=i;
            pr.push_back(i);
            for(ll j= i*i;j<maxlen;j+=i){
                prime[j]=i;
            }
        }
    }
    
    while(t--){
        ll a,b;cin>>a>>b;
        ll ans=1;
        for(ll p:pr){
            if((a%p==0) && (b%p==0))ans++;
            while(a%p==0)a/=p;
            while(b%p==0)b/=p;
        }
        if(a==b && a!=1)ans++;
        cout<<ans<<endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;

// void solve(){
//     string s;cin>>s;
//     ll n=s.size();
//     ll l=0,r=0;
//     map<char,ll> cnt;
//     ll ans=0;
//     while(r<n){
//         while(r<n && (s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u')){
//             cnt[s[r]]++;
//             r++;
//             if(cnt.size()==5)break;
//         }
//         while(cnt.size()==5){
//             ans+=1;
//             cnt[s[l]]--;
//             if(cnt[s[l]]==0){
//                 break;
//             }
//         }
//         cnt.clear();
//         l=++r;
//     }
//     cout<<ans<<endl;
// }

// int main(){
//     int t=1;
//     cin>>t;
//     while(t--)solve();
//     return 0;
// }