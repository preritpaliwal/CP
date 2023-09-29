#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> r(n),c(n);
    ll minr=1e9,sumr=0,minc=1e9,sumc=0;
    for(int i=0;i<n;i++){cin>>r[i];minr=min(minr,r[i]);sumr+=r[i];}for(int j=0;j<n;j++){cin>>c[j];minc=min(minc,c[j]);sumc+=c[j];}
    cout<<min(n*minc+sumr,n*minr+sumc)<<endl;;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}