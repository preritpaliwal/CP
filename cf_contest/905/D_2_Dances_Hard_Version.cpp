#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    multiset<ll> b;
    a[0]=1;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        b.insert(tmp);
    }
    sort(a.begin(),a.end());
    ll del=0;
    for(int i=n-1;i>=1;i--){
        if(b.upper_bound(a[i])==b.end()){
            del++;
        }
        else{
            b.erase(b.upper_bound(a[i]));
        }
    }
    // cerr<<"del:"<<del<<"\n";
    // for(auto i:b){
    //     cerr<<i<<" ";
    // }
    // cerr<<"\n";
    ll larg=*b.rbegin();
    ll ans= m*del + max(0ll,m-larg+1);
    cout<<ans<<"\n";
    return ;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}