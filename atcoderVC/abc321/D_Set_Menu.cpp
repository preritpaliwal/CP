#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m,p;cin>>n>>m>>p;vector<ll> a(n),b(m);for(ll &i:a)cin>>i;for(ll &i:b)cin>>i;
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    vector<ll> pre(m,0);
    pre[0]=b[0];for(int i=1;i<m;i++)pre[i]=b[i]+pre[i-1];
    int j=m-1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll av=p-a[i];
        while(j>=0 && b[j]>av){
            j--;
        }
        ans+=(a[i])*m+((j>=0)?pre[j]:0)+av*(m-1-j);
    }
    cout<<ans<<endl;
    return ;
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
