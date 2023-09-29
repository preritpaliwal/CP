#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<string> v;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp;cin>>tmp;v.push_back(tmp);
    }
    if(v[0][0]!='s'){cout<<"No\n";return 0;}
    vector<string> vis(n,string (m,'0'));
    queue<pair<int,int>> q;
    q.push({0,0});
    int di[]={0,1,0,-1};
    int dj[]={1,0,-1,0};
    string snuke="snuke";
    vis[0][0]='1';
    while(!q.empty()){
        auto cur=q.front();q.pop();
        char nextchar;
        if(v[cur.first][cur.second]=='s'){
            nextchar='n';
        }
        else if(v[cur.first][cur.second]=='n'){
            nextchar='u';
        }
        else if(v[cur.first][cur.second]=='u'){
            nextchar='k';
        }
        else if(v[cur.first][cur.second]=='k'){
            nextchar='e';
        }
        else if(v[cur.first][cur.second]=='e'){
            nextchar='s';
        }
        for(int i=0;i<4;i++){
            int ni=cur.first+di[i],nj=cur.second+dj[i];
            if(ni<0 || ni>=n || nj<0 || nj>=m)continue;
            if(nextchar==v[ni][nj] && vis[ni][nj]=='0'){
                q.push({ni,nj});vis[ni][nj]='1';
            }
        }
    }
    if(vis[n-1][m-1]=='1')cout<<"Yes\n";
    else cout<<"No\n";
}