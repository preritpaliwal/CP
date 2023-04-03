#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int mod = 1000007;

void solve(ll n,ll d){
    if(n==0){
        cout<<0<<endl;
        return;
    }
    map<ll,ll> mp;

    for(ll i = 2;i*i<=n;i++){
        if(n%i==0){
            ll k = 0;
            while(n%i==0){
                n/=i;
                k++;
            }
            mp[i] = k;
        }
    }
    if(n>1){
        mp[n] = 1;
    }
    mp[2]+=d;
    mp[5]+=d;
    ll ans = 1;
    for(auto &tmp:mp){
        // cout<<"tmp: "<<tmp.first<<","<<tmp.second<<endl;
        ans *= (2*(tmp.second) + 1)%mod;
    }
    cout<< ((ans*2)%mod - 1)%mod<<endl;
}

int main(){
    ll n = 1,d = 1;
    while(true){
        scanf("%lli %lli",&n,&d);
        if(n==0 && d==0){
            break;
        }
        solve(n,d);
    }
    return 0;
}