#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    ll sum=0;
    for(int i=0;i<n-1;i++){
        ll a;cin>>a;
        sum+=a;
    }
    cout<<-sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}