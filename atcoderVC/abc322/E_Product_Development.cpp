// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;
// bool over(ll a,ll b,ll base){
//     int cnt=0;
//     while(a!=0 && b!=0){
//         if((a%base+b%base)>=base)return true;
//         a/=base;b/=base;cnt++;
//     }
//     return false;
// }
// int main(){
//     ll n,k,p;cin>>n>>k>>p;ll maxlen=1,_=k;
//     while(_--)maxlen*=(p+1);
//     vector<ll> dp(maxlen,1e15);
//     dp[0]=0;
//     for(ll i=0;i<n;i++){
//         ll ci;cin>>ci;ll p1=1;set<ll> s{0};
//         for(ll idx=0;idx<k;idx++){
//             ll at;cin>>at;
//             for(ll j=maxlen-1;j>=0;j--){
//                 if(dp[j]==-1)continue;
//                 ll bit=(j/p1)%(p+1);
//                 ll state=min(bit+at,p)*p1;
//                 dp[state]=min(dp[state],dp[j]+ci);
//             }
//             p1*=(p+1);
//         }
//     }
//     cout<<((dp[maxlen-1]>=1e15)?-1:dp[maxlen-1])<<endl;
//     return 0;
// }
