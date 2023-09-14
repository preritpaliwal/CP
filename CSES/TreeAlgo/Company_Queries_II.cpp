#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<vector<int>> nexts;
vector<int> height;

void fillNext(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<nexts[i].size();j++){
            nexts[i][j] = nexts[nexts[i][j-1]][j-1];
        }
    }
}

void fillHeight(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch!=pp){
            height[ch] = height[nn]+1;
            fillHeight(ch,nn);
        }
    }
}

int lca(int a,int b){
    if(height[a]>height[b]){
        int k = a;
        a = b;
        b = k;
    }
    // bring to same height
    int dif = height[b]-height[a];
    for(int i = (int)nexts[b].size()-1;i>=0;i--){
        if(dif&(1<<i)){
            b = nexts[b][i];
        }
    }
    if(a==b){
        return a;
    }
    // take one one step to find LCA;
    for(int i = (int)nexts[a].size()-1;i>=0;i--){
        if(nexts[a][i]!=nexts[b][i]){
            a = nexts[a][i];
            b = nexts[b][i];
        }
    }
    return nexts[a][0];
}

int main(){
    int q;
    cin>>n>>q;
    adj.resize(n+1);
    height.resize(n+1,0);
    nexts.resize(n+1, vector<int> ((int)log2(n)+1,0));
    for(int i=2;i<=n;i++){
        int _;
        cin>>_;
        adj[_].push_back(i);
        adj[i].push_back(_);
        nexts[i][0] = _;
    }
    fillHeight(1,0);
    fillNext();
    for(int i = 0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}