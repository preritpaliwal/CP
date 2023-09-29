#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,m;cin>>n>>m;
    vector<vector<char>> grid(n,vector<char> (m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>grid[i][j];
    vector<vector<int>> g(n,vector<int> (m,1)),vis(n,vector<int> (m,-1));
    pair<int,int> st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='S'){
                st.first=i;st.second=j;
            }
            if(grid[i][j]=='G'){
                en.first=i;en.second=j;
            }
            if(grid[i][j]=='.' || grid[i][j]=='G' || grid[i][j]=='S')continue;
            g[i][j]=0;
            if(grid[i][j]=='<'){
                // cerr<<"here for <: "<<i<<" "<<j<<endl;
                for(int k=j-1;k>=0;k--){
                    if(grid[i][k]=='.')g[i][k]=0;
                    else break;
                }
            }
            else if(grid[i][j]=='^'){
                // cerr<<"here for ^: "<<i<<" "<<j<<endl;
                for(int k=i-1;k>=0;k--){
                    if(grid[k][j]=='.')g[k][j]=0;
                    else break;
                }
            }
            else if(grid[i][j]=='>'){
                // cerr<<"here for >: "<<i<<" "<<j<<endl;
                for(int k=j+1;k<m;k++){
                    if(grid[i][k]=='.')g[i][k]=0;
                    else break;
                }
            }
            else if(grid[i][j]=='v'){
                // cerr<<"here for v: "<<i<<" "<<j<<endl;
                for(int k=i+1;k<n;k++){
                    if(grid[k][j]=='.')g[k][j]=0;
                    else break;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<g[i][j];
    //     }
    //     cout<<endl;
    // }
    queue<pair<int,int>> q;
    q.push(st);
    vis[st.first][st.second]=0;
    int di[]={0,1,0,-1};
    int dj[]={1,0,-1,0};
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int ni=cur.first+di[i],nj=cur.second+dj[i];
            if(ni<0 || ni>=n || nj<0 || nj>=m)continue;
            if(vis[ni][nj]==-1 && g[ni][nj]==1){
                vis[ni][nj]=vis[cur.first][cur.second]+1;
                q.push({ni,nj});
            }
        }
    }
    cout<<vis[en.first][en.second]<<endl;
    return 0;
}