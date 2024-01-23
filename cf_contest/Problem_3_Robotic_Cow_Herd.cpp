#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("roboherd.in", "r", stdin);   // input.txt
    freopen("roboherd.out", "w", stdout); // output.txt

    ll n,k;cin>>n>>k;
    map<ll,ll> dp;
    dp[0]=1;
    for(ll i=0;i<n;i++){
        ll mi;cin>>mi;
        map<ll,ll> tmp;
        for(int j=0;j<mi;j++){
            ll cur;cin>>cur;
            for(auto &p:dp){
                tmp[p.first+cur]+=p.second;
            }
        }
        dp=tmp;
    }
    ll ans=0;
    for(auto &p:dp){
        if(p.second<k){
            k-=p.second;
            ans+=p.first*p.second;
        }
        else{
            ans+=p.first*k;
            k=0;
            break;
        }
    }
    if(k!=0){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
    }
}