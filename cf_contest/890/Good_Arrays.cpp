#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    if(n==1){cout<<"NO\n";;return;}
    ll s=0,minS=0,minV=1e9+1;
    for(int i=1;i<=n;i++){
        s+=v[i];
        minV=min(minV,v[i]);
        if(v[i]==1){
            minS+=2;
        }
        else{
            minS+=1;
        }
    }
    if(minS>s){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}