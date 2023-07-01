#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> subTreeSize;
int n;

int getSubTree(int cur,int par = -1){
    int st = 0;
    for(int i:adj[cur]){
        if(i!=par){
            st += 1+getSubTree(i,cur);
        }
    }
    return subTreeSize[cur] = st;
}

void solve(){
    adj.clear();
    subTreeSize.clear();
    cin>>n;
    adj.resize(n+1);
    for(int i = 2;i<=n;i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    subTreeSize.resize(n+1,0);
    getSubTree(1);
    for(int i = 1;i<=n;i++){
        cout<<subTreeSize[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}