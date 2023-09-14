#include <bits/stdc++.h>
using namespace std;

int n,dim;
vector<vector<int>> adj;
vector<vector<int>> nexts;
vector<int> h;
vector<int> sums;

void dfs(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch==pp){
            continue;
        }
        h[ch]=h[nn]+1;
        nexts[ch][0]=nn;
        dfs(ch,nn);
    }
}

void pushDfs(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch==pp){
            continue;
        }
        pushDfs(ch,nn);
        sums[nn]+=sums[ch];
    }
}

int lca(int a,int b){
    if(h[a]>h[b]){
        swap(a,b);
    }
    int dif=h[b]-h[a];
    for(int i=dim-1;i>=0;i--){
        if(dif&(1<<i)){
            b=nexts[b][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=dim-1;i>=0;i--){
        if(nexts[a][i]!=nexts[b][i]){
            a=nexts[a][i];
            b=nexts[b][i];
        }
    }
    return nexts[a][0];
}

int main(){
    int q;
    cin>>n>>q;
    dim = log2(n)+1;
    adj.resize(n+1);
    nexts.resize(n+1,vector<int> (dim,0));
    h.resize(n+1,0);
    sums.resize(n+1,0);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    dfs(1,0);
    for(int j=1;j<dim;j++){
        for(int i=1;i<=n;i++){
            nexts[i][j]=nexts[nexts[i][j-1]][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        sums[a]+=1;
        sums[b]+=1;
        int lc = lca(a,b);
        sums[lc]-=1;
        sums[nexts[lc][0]]-=1;
    }
    pushDfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<sums[i]<<" ";
    }
    cout<<endl;
}