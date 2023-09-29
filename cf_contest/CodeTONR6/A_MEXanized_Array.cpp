#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n,k,x;cin>>n>>k>>x;
    if(k>n){cout<<-1<<endl;return;}
    if(k>x+1){cout<<-1<<endl;return;}
    ll ans=0;
    for(int i=1;i<k;i++){
        ans+=i;
    }
    if(x==k){x--;}
    ans+= (1ll*x)*(n-k);
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}