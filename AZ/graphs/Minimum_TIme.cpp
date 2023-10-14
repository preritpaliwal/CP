#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int>> mat(n,vector<int> (m,0));
        auto vis=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;cin>>c;
                if(c=='.')mat[i][j]=1;
            }
        }
        int si,sj,ei,ej;cin>>si>>sj>>ei>>ej;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{si,sj}});
        vis[si][sj]=1;
        int di[]={0,1,0,-1,1,1,-1,-1};
        int dj[]={1,0,-1,0,1,-1,1,-1};
        int ans=-1;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            if(cur.second.first==ei && cur.second.second==ej){
                ans=cur.first;
                break;
            }
            int ni=cur.second.first,nj=cur.second.second;
            for(int i=0;i<8;i++){
                int ti=di[i]+ni,tj=dj[i]+nj;
                if(ti<0 || tj<0 || ti>=n || tj>=m)continue;
                if(vis[ti][tj]==0 && mat[ti][tj]==1){
                    vis[ti][tj]=1;
                    q.push({cur.first+1,{ti,tj}});
                }
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}