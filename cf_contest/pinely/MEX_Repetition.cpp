#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    ll missing=(1LL*n*(n+1))/2;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        missing-=v[i];
    }
    int sh=k%(n+1);
    if(sh==0){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }cout<<endl;
        return;
    }
    // cerr<<"sh: "<<sh<<endl;
    vector<int> ans(n);
    for(ll i=0;i<n;i++){
        if(i+sh<n){
            ans[i+sh]=v[i];
        }
        else if(i+sh==n){
            
        }
        else{
            ans[(i+sh-1)%n]=v[i];
        }
    }
    ans[(n-1+sh)%n]=missing;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}