#include <bits/stdc++.h>
using namespace std;
int n;
int dim;
vector<vector<int>> adj;
vector<vector<int>> nexts;
vector<int> h;
vector<int> pow2;

void dfs(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch!=pp){
            h[ch]=h[nn]+1;
            nexts[ch][0]=nn;
            dfs(ch,nn);
        }
        
    }
}

int dist(int a,int b){
    if(h[a]>h[b]){
        swap(a,b);
    }
    int dif = h[b]-h[a];
    int distance = 0;
    for(int i = dim-1;i>=0;i--){
        if(dif&(1<<i)){
            b = nexts[b][i];
            distance += pow2[i];
        }
    }
    if(a==b){
        return distance;
    }
    for(int i = dim-1;i>=0;i--){
        if(nexts[a][i]!=nexts[b][i]){
            a = nexts[a][i];
            b = nexts[b][i];
            distance += 2*pow2[i];
        }
    }
    return distance +2;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q;
    cin>>n>>q;
    dim = log2(n)+1;
    adj.resize(n+1);
    h.resize(n+1,0);
    pow2.resize(dim,1);
    nexts.resize(n+1,vector<int> (dim,0));
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int j=1;j<dim;j++){
        for(int i = 1;i<=n;i++){
            nexts[i][j] = nexts[nexts[i][j-1]][j-1];
        }
    }
    for(int i=1;i<dim;i++){
        pow2[i] = 2*pow2[i-1];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<dist(a,b)<<endl;
    }
    
}