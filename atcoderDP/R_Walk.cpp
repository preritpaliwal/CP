#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
vector<vector<ll>> v[64];
int main(){
    ll n,k;cin>>n>>k;
    for(int i=0;i<64;i++)v[i].resize(n,vector<ll> (n,0));
    for(int j=0;j<n;j++)for(int i=0;i<n;i++)cin>>v[0][i][j];
    vector<vector<ll>> ans(n,vector<ll> (n,0));
    for(int i=0;i<n;i++)ans[i][i]=1;
    for(int p=0;p<64;p++){
        if(p!=0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int l=0;l<n;l++){
                        v[p][i][j]=(v[p][i][j]+(v[p-1][i][l]*v[p-1][l][j])%mod)%mod;
                    }
                }
            }
        }
        
        if(k&(1ll<<p)){
            vector<vector<ll>> tmp(n,vector<ll> (n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int l=0;l<n;l++){
                        tmp[i][j]=(tmp[i][j]+(ans[i][l]*v[p][l][j])%mod)%mod;
                    }
                }
            }
            ans=tmp;
        }
    }
    ll ans1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans1=(ans1+ans[i][j])%mod;
        }
    }
    cout<<ans1<<endl;
}