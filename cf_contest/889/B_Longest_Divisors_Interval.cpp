#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    ll n;cin>>n;
    int ans=1;
    for(int i=2;i<=min(65LL,n);i++){
        if(n%i==0){
            ans++;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}