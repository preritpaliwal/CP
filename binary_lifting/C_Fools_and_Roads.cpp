#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,maxlen=log2(2e5);
vector<vector<ll>> adj;
vector<vector<ll>> ne;
vector<ll> freq;
vector<ll> h;
void fillNext(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch==pp)continue;
        ne[ch][0]=nn;
        h[ch]=1+h[nn];
        fillNext(ch,nn);
    }
}
ll lca(ll a,ll b){
    if(h[a]>h[b])swap(a,b);
    int dif=h[b]-h[a];
    for(int i=maxlen-1;i>=0;i--){
        if((1<<i)&dif){
            b=ne[b][i];
        }
    }
    if(b==a)return a;
    for(int i=maxlen-1;i>=0;i--){
        if(ne[a][i]!=ne[b][i]){
            a=ne[a][i];b=ne[b][i];
        }
    }
    return ne[a][0];
}
void dfs(ll nn,ll pp){
    for(ll ch:adj[nn]){
        if(ch==pp)continue;
        dfs(ch,nn);
        freq[nn]+=freq[ch];
    }
}
int main(){
    cin>>n;adj.resize(n+1);ne.resize(n+1,vector<ll> (maxlen,0));freq.resize(n+1,0),h.resize(n+1,0);
    vector<pair<ll,ll>> edges;
    for(int i=1;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);edges.push_back({a,b});}
    ne[1][0]=0;
    fillNext(1,0);
    for(int i=1;i<maxlen;i++){
        for(int j=1;j<=n;j++){
            ne[j][i]=ne[ne[j][i-1]][i-1];
        }
    }
    int q;cin>>q;
    while(q--){
        ll a,b;cin>>a>>b;
        ll c=lca(a,b);
        freq[a]++;freq[b]++;
        freq[c]-=2;
    }
    dfs(1,0);
    for(int i=0;i<edges.size();i++){
        if(ne[edges[i].first][0]==edges[i].second){
            cout<<freq[edges[i].first]<<" ";
        }
        else{
            cout<<freq[edges[i].second]<<" ";
        }
    }
}