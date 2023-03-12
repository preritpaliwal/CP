#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    ll n,x,p;
    cin>>n>>x>>p;
    bool pos = false;
    ll sum = 0;
    vector<ll> sums;
    for(ll i = 1;i<=min(2*n,p);i++){
        sum += i;
        sum = ((sum%n) + n)%n;
        sums.push_back(sum);
        if((sum+x)%n==0){
            pos = true;
            break;
        }
    }
    if(pos){
        cout<<"Yes\n";
    }
    else{
        
        cout<<"No\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}