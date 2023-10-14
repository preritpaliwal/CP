#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll ra(ll a,ll b){
    return rand()%b +a;
}

void solve(){
    int n=ra(1,20);
    cout<<n<<" "<<ra(0,20)<<ra(1,n+1)<<endl;
}

int main(){
    ll t=ra(1,10);
    cout<<t<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}