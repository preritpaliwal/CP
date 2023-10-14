#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    for(ll &i:a)cin>>i;for(ll &i:b)cin>>i;
    ll amax=0,amin=2e9,bmax=0,bmin=2e9,suma=0;
    for(int i=0;i<n;i++){
        amax=max(amax,a[i]);amin=min(amin,a[i]);suma+=a[i];
    }
    for(int i=0;i<m;i++){
        bmax=max(bmax,b[i]);bmin=min(bmin,b[i]);
    }
    if(amax<bmin){
        if(k%2==1){
            cout<<suma-amin+bmax<<endl;
        }
        else{
            cout<<suma<<endl;
        }
    }
    else if(bmax<amin){
        if(k%2==1){
            cout<<suma<<endl;
        }
        else{
            cout<<suma-amax+bmin<<endl;
        }
    }
    else{
        if(k%2==1){
            cout<<suma-amin+bmax<<endl;
        }
        else{
            cout<<suma-amax-amin+min(amax,bmax)+min(amin,bmin)<<endl;
        }
    }
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}