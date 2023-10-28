#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll x,k;cin>>x>>k;
    while(true){
        ll sum=0;
        ll tmp=x;
        while(tmp!=0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum%k==0){
            cout<<x<<"\n";
            return;
        }
        x++;
    }
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