#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<vector<ll>> adj;
// vector<double> pr;
vector<ll> outdeg,vis;

double dfs(ll nn){
    if(nn=n)return 1.0;
    
}

void solve(){
    cin>>n>>m;
    adj.clear();outdeg.clear();adj.resize(n+1);outdeg.resize(n+1,0),vis.clear(),vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        outdeg[a]++;
    }
    vis[1]=1;
    cout<<dfs(1,0)<<endl;;
}

int main(){
    // pr.clear();
    // pr.resize(2e5+1,0);
    // pr[1]=1;
    // pr[2]=(double)0.25;
    // for(int i=3;i<pr.size();i++){
    //     pr[i]=(1.0/(double)i*i + (1.0 - (3.0*i-2.0)/(i*i))*pr[i-2]);
    // }
    ll t;cin>>t;
    while(t--)solve();
    return 0;
}