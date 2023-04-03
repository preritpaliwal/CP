#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(m, vector<ll> (n,-1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>v[j][i];
        }
    }
    for(int i = 0;i<m;i++){
        sort(v[i].begin(),v[i].end());
    }
    ll ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            ans += v[i][j]*(j) - v[i][j]*(n-1-j);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}