
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m;cin>>n>>m;
    n=n%m;
    ll tmp=m;
    while(tmp%2==0)tmp>>=1;
    if(n%tmp!=0){
        cout<<-1<<endl;
        return;
    }
    ll ans=0;
    while(n!=0){
        ans+=n;
        n=(2*n)%m;
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