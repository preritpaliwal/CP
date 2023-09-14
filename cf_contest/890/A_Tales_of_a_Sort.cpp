#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n+1),pre(n+1,0);
    for(int i=1;i<=n;i++){cin>>v[i];pre[i]=max(pre[i-1],v[i]);}
    for(int i=n;i>0;i--){
        if(pre[i]!=v[i]){
            cout<<pre[i]<<endl;
            return;
        }
    }
    cout<<0<<endl;
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}