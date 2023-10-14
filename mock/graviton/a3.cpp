#include <bits/stdc++.h>
using namespace std;
int n,m,e;
vector<vector<int>> adj[2];
set<pair<int,int>> taken;
vector<int> deg[2];
void solve(){
    cin>>n>>m>>e;
    adj[0].clear();adj[1].clear();
    adj[0].resize(n+1);
    adj[1].resize(m+1);
    deg[0].clear();deg[1].clear();
    deg[0].resize(n+1,0);
    deg[1].resize(m+1,0);
    taken.clear();
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
        deg[0][a]++;
        deg[1][b]++;
    }
    int ans=0;
    while(taken.size()<e){
        ans++;
        int cur=0,cur2=0;
        for(int i=1;i<=n;i++){
            if(deg[0][i]>deg[0][cur]){
                cur=i;
            }
        }
        for(int i=1;i<=m;i++){
            if(deg[1][i]>deg[1][cur2]){
                cur2=i;
            }
        }
        int use=0;
        if(deg[0][cur]<deg[1][cur2]){cur=cur2;use=1;}
        for(int ch:adj[use][cur]){
            if(use==0){
                if(taken.find({cur,ch})!=taken.end())continue;
            }
            else{
                if(taken.find({ch,cur})!=taken.end())continue;
            }
            deg[use][cur]--;
            deg[1-use][ch]--;
            if(use==1){
                taken.insert({ch,cur});
            }
            else{
                taken.insert({cur,ch});
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}