#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod = 1e9 + 7;
vector<vector<ll>> beauty;

ll solve1(vector<ll> &a, int l,int r){
    if(beauty[l][r]==INT_MAX){
        vector<ll> premax(n,0),postmin(n,0);
        premax[l] = a[l];
        postmin[r] = b[r];
        for(int i = l+1;i<=r;i++){
            premax[i] = max(a[i],premax[i]);
            postmin[r+l-i] = min(a[l+r-i],postmin[l+r-i+1]);
        }
        ll ans = 0, s = n+1,e = -1;
        for(int i = l;i<=r;i++){
            if(a[i]!=premax[i]){
                s = i;
            }
            if(a[i])
        }
    }
    return beauty[l][r];
}

void solve(){
    ll n;
    cin>>n;
    beauty.clear();
    beauty.resize(n);
    for(int i = 0;i<n;i++){
        beauty[i].resize(n);
        for(int j = 0;i<n;j++){
            beauty[i][j] = INT_MAX;
        }
    }
    for(int i = 0;i<n;i++){
        beauty[i][i] = 0;
    }
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    solve1(a,0,n-1);
}

int main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}