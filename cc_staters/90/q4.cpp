#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9+7;

ll printNcR(ll n, ll r){
    if(r>n){
        return n;
    }
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    // cout << p << endl;
    return p;
}


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    ll twos = 1;
    for(int i = n-1;i>=0;i--){
        ll prev = printNcR(i,v[i]-1);
        ll after = twos;
        twos = twos<<1;
        ans += prev*after;
        cout<<"i,ans: "<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
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