#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<vector<pair<ll,ll>>> adj;
vector<ll> inf;
vector<ll> tocheck;
vector<ll> date;
int main(){
    cin>>n>>m;adj.resize(n+1);date.resize(n+1,-1);
    for(ll i=0;i<m;i++){ll a,b,c;cin>>a>>b>>c;adj[a].push_back({c,b});adj[b].push_back({c,a});}
    for(ll i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());
    ll infn;cin>>infn;for(ll i=0;i<infn;i++){ll a;cin>>a;inf.push_back(a);tocheck.push_back(0);date[a]=0;}
    ll d;cin>>d;
    for(ll i=1;i<=d;i++){
        ll x;cin>>x;
        vector<ll> tmp=inf;
        for(ll j=0;j<tmp.size();j++){
            for(ll k=tocheck[j];k<adj[tmp[j]].size();k++){
                if(adj[tmp[j]][k].first>x)break;
                tocheck[j]=k+1;
                if(date[adj[tmp[j]][k].second]==-1){
                    date[adj[tmp[j]][k].second]=i;
                    inf.push_back(adj[tmp[j]][k].second);
                    tocheck.push_back(0);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<date[i]<<endl;
    }
    cout<<endl;
}