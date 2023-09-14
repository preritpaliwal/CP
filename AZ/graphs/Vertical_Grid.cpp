#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<string> mat;
vector<string> vis;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
int dfs(int i,int j){
    int ret=1;
    for(int k=0;k<4;k++){
        int ni=i+di[k],nj=j+dj[k];
        if(ni<0 || ni>=n || nj<0 || nj>=10)continue;
        if(mat[i][j]==mat[ni][nj] && vis[ni][nj]=='0'){
            vis[ni][nj]='0'+mat[i][j];ret+=dfs(ni,nj);
        }
    }
    return ret;
}
void set0(int i,int j,char c){
    for(int k=0;k<4;k++){
        int ni=i+di[k],nj=j+dj[k];
        if(ni<0 || ni>=n || nj<0 || nj>=10)continue;
        if(vis[ni][nj]=='0'+c){
            mat[ni][nj]='0';vis[ni][nj]='1';set0(ni,nj,c);
        }
    }
}
int main(){
    cin>>n>>k;mat.resize(n);for(int i=0;i<n;i++)cin>>mat[i];
    while(true){
        vis.clear();
        vis.resize(n,"0000000000");
        bool updated=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                if(vis[i][j]=='0' && mat[i][j]!='0'){
                    vis[i][j]='0'+mat[i][j];
                    if(dfs(i,j)>=k){
                        char c=mat[i][j];
                        mat[i][j]='0';
                        vis[i][j]='1';
                        set0(i,j,c);
                        updated=true;
                    }
                }
            }
            cerr<<vis[i]<<endl;
        }
        if(!updated){break;}
        cerr<<"before swaps: \n";
        for(int i =0;i<n;i++)cerr<<mat[i]<<endl;
        for(int j=0;j<10;j++){
            if(int i=n-1;i>0;i--){
                if()
            }
        }
        cerr<<"after swaps: \n";
        for(int i =0;i<n;i++)cerr<<mat[i]<<endl;
    }
    for(int i =0;i<n;i++)cout<<mat[i]<<endl;
}