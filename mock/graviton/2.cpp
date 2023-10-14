#include <bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>> mp;
ll prime[(int)1e7+1];
void solve(){
    int n;cin>>n;vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    ll cnt=0;
    for(int i:a){
        while(i!=1){
            ll p=prime[i];
            mp[p].push_back(cnt);
            while(i%p==0){
                i/=p;
            }            
        }
        cnt++;
    }
    vector<ll> ans(n,1);
    for(int i=0;i<n;i++){
        
    }
}

int main(){
    prime[0]=prime[1]=1;
    for(ll i=2;i<=1e7;i++){
        if(prime[i]==0){
            prime[i]=i;
            for(ll j=i*i;j<=1e7;j+=i){
                prime[j]=i;
            }
        }
    }
    int t;cin>>t;
    while(t--)solve();
    return 0;
}