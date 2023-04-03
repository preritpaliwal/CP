#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkm(ll k, ll a, ll b, ll c){
    if(a*c<0){
        return false;
    }
    return k<b+sqrt(4*a*c);
}

bool checkl(ll k, ll a, ll b, ll c){
    if(a*c<0){
        return false;
    }
    return k>b-sqrt(4*a*c);
}

void solve(){
    ll n,m;
    cin>> n>>m;
    vector<ll> k(n);
    for(ll i=0; i<n; i++){
        cin>> k[i];
    }
    vector<vector<ll>> p(m);
    for(ll i=0; i<m; i++){
        vector<ll> tmp(3);
        cin>>tmp[0]>>tmp[1]>>tmp[2];
        p[i] = tmp;
    }
    sort(k.begin(), k.end());
    for(ll i = 0;i<m;i++){
        ll a = p[i][0], b = p[i][1], c = p[i][2];
        ll l = 0;
        ll r = n-1;
        ll maxK = l;
        while(l<=r){
            ll mid = (l+r)/2;
            // cout<<"mid: "<<mid<<endl;
            if(checkm(k[mid], a, b, c)){
                l = mid+1;
                maxK = mid;
            }
            else{
                r = mid-1;
            }
        }
        if(checkl(k[maxK],a,b,c) && checkm(k[maxK],a,b,c)){
            cout<<"YES\n";
            cout<<k[maxK]<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}