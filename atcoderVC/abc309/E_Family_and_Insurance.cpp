#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> adj;
vector<int> ins;
void dfs(int nn,int pp){
    for(int ch:adj[nn]){
        if(ch==pp)continue;
        ins[ch]=max(ins[ch],max(0,ins[nn]-1));
        dfs(ch,nn);
    }
}
int main(){
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    ins.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int b;cin>>b;adj[i+2].push_back(b);adj[b].push_back(i+2);
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ins[a]=max(ins[a],b+1);
    }
    dfs(1,0);
    int cnt=0;
    for(int i=1;i<=n;i++)if(ins[i]>0)cnt++;
    cout<<cnt<<endl;
    return 0;
}