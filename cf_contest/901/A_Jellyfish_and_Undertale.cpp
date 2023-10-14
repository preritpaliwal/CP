#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll a,b,n;cin>>a>>b>>n;
    ll ans=b;
    for(int i=0;i<n;i++){
        ll cur;cin>>cur;
        ans+=min(a-1,cur);
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}