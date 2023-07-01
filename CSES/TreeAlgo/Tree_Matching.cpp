#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> dist;
int nMatch = 0;
set<int> match;

void dfs(int cur,int par=-1){
    for(int u:adj[cur]){
        if(u!=par){
            dist[u] = 1+dist[cur];
            dfs(u,cur);
        }
    }
}

void matching(int cur, int par=-1,bool taken = false){
    // cerr<<"cur,taken: "<<cur<<","<<taken<<" "<<par<<endl;
    bool once = true;
    for(int u:adj[cur]){
        if(u!=par){
            // cout<<"cur, u: "<<cur<<", "<<u<<endl;
            if(!taken && once){
                once = false;
                match.insert(u);
                matching(u,cur,true);
            }
            else{
                matching(u,cur,false);
            }
        }
    }
    if(!once && !taken){
        match.insert(cur);
    }
}

int main(){
    cin>>n;
    adj.clear();
    adj.resize(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for(int i = 0;i<n;i++){
    //     cerr<<"i="<<i<<": ";
    //     for(int u:adj[i]){
    //         cerr<<u<<" ";
    //     }
    //     cerr<<endl;
    // }
    dist.resize(n+1,0);
    dist[1] = 0;
    dfs(1);
    int endp = -1;
    for(int i = 1;i<=n;i++){
        if(endp==-1){
            endp=i;
        }
        else if(dist[endp]<dist[i]){
            endp = i;
        }
    }
    // cerr<<endp<<endl;
    matching(endp);
    // for(int el:match){
    //     cerr<<el<<" ";
    // }
    // cerr<<endl;
    cout<<match.size()/2<<endl;
}