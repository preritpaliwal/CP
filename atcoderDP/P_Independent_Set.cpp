#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int n;
vector<vector<int>> adj;
vector<ll> indp[2];
void dfs(int nn,int pp){
    indp[0][nn]=1;
    indp[1][nn]=1;
    for(int ch:adj[nn]){
        if(ch!=pp){
            dfs(ch,nn);
            indp[1][nn]=(indp[1][nn]*indp[0][ch])%mod;
            indp[0][nn]=(indp[0][nn]*((indp[0][ch]+indp[1][ch])%mod))%mod;
        }
    }
}
int main(){
    cin>>n;adj.resize(n+1);
    indp[0].resize(n+1,0);indp[1].resize(n+1,0);
    for(int i=1;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    dfs(1,0);
    cout<<(indp[0][1]+indp[1][1])%mod<<endl;
}