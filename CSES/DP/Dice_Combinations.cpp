#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

int main(){
    int n;cin>>n;
    // cout<<solve(n,6)<<endl;
    vector<ll> v(n+1,0);
    v[0]=1;
    for(int i=0;i<=n;i++){
        for(int j=1;j<7;j++){
            if(i+j<=n)v[i+j]=(v[i+j]+v[i])%mod;
        }
        // cout<<v[i]<<endl;
    }
    cout<<v[n]<<endl;
}