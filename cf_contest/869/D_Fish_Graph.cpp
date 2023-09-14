#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> cycleNodes;
vector<pair<int,int>> ans;


void dfs(int nn, int pp=0){

}

void solve(){
    cin>>n>>m;
    adj.clear();
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        if(adj[i].size()>=4){
            queue<pair<int,int>> q;
            q.push({i,0});
            vector<int> vis(n+1,-1);
            vis[i]=0;
            pair<int,int> cycle{-1,-1};
            while(!q.empty()){
                auto cur=q.front();q.pop();
                // cerr<<cur.first<<endl;
                for(int u:adj[cur.first]){
                    if(u==cur.second)continue;
                    if(vis[u]!=-1){
                        // cerr<<u<<"done cycle\n";
                        cycle.first=u;
                        cycle.second=cur.first;
                        break;
                    }
                    else{
                        // cerr<<"pushing: "<<u<<endl;
                        q.push({u,cur.first});
                        vis[u]=cur.first;
                    }
                }
                if(cycle.first!=-1){
                    break;
                }
            }
            if(cycle.first==-1){
                continue;
            }
            ans.push_back(cycle);
            pair<int,int> used{-1,-1};
            int cur=cycle.first;
            while(vis[cur]!=0){
                ans.push_back({cur,vis[cur]});
                used.first=cur;
                cur=vis[cur];
            }
            cur=cycle.second;
            while(vis[cur]!=0){
                ans.push_back({cur,vis[cur]});
                used.second=cur;
                cur=vis[cur];
            }
            int cnt=0;
            for(int tmp:adj[i]){
                if(tmp==used.first || tmp==used.second)continue;
                ans.push_back({i,tmp});
                cnt++;
                if(cnt==2)break;
            }
            cout<<"YES\n"<<ans.size()<<endl;
            for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
        // cerr<<"------\n\n";
    }
    return 0;
}