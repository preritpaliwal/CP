#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj,vis;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
void dfs(int ni,int nj,int color,int &na,int &nb){
    for(int i=0;i<4;i++){
        int ci=ni+di[i],cj=nj+dj[i];
        if(ci<0 || ci>=n || cj<0 || cj>=n){
            nb++;
            continue;
        }
        else{
            if(vis[ci][cj]==-1){
                if(adj[ci][cj]==adj[ni][nj]){
                    na++;
                    vis[ci][cj]=color;
                    dfs(ci,cj,color,na,nb);
                }
                else{
                    nb++;
                }
            }
        }
    }
}
int main(){
    cin>>n;adj.resize(n,vector<int> (n,0));vis.resize(n,vector<int> (n,-1));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){char c;cin>>c;if(c=='#')adj[i][j]=1;}
	vector<int> area,peri;int color=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==-1 && adj[i][j]==1){
                vis[i][j]=color;
                int na=1,nb=0;
                dfs(i,j,color++,na,nb);
                area.push_back(na);peri.push_back(nb);
            }
        }
    }
    int ma=0;
    for(int i=0;i<color;i++){
        ma=max(ma,area[i]);
    }
    int mp=1e9;
    for(int i=0;i<color;i++){
        if(ma==area[i])mp=min(mp,peri[i]);
    }
    cout<<ma<<" "<<mp<<endl;
}