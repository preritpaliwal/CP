#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,m;cin>>n>>m;vector<string> v;v.resize(n);for(string &s:v)cin>>s;
    vector<vector<int>> exp(n,vector<int> (m,0)),vis(n,vector<int> (m,0));
    queue<pair<int,int>> q;
    q.push({1,1});
    vis[1][1]=1;
    while(!q.empty()){
        auto c=q.front();q.pop();
        if(exp[c.first][c.second]==1)continue;
        exp[c.first][c.second]=1;
        for(int i=c.first+1;i<n;i++){
            if(v[i][c.second]=='.'){
                vis[i][c.second]=1;
            }
            else{
                q.push({i-1,c.second});
                break;
            }
        }
        for(int i=c.first-1;i>=0;i--){
            if(v[i][c.second]=='.'){
                vis[i][c.second]=1;
            }
            else{
                q.push({i+1,c.second});
                break;
            }
        }
        for(int i=c.second+1;i<m;i++){
            if(v[c.first][i]=='.'){
                vis[c.first][i]=1;
            }
            else{
                q.push({c.first,i-1});
                break;
            }
        }
        for(int i=c.second-1;i>=0;i--){
            if(v[c.first][i]=='.'){
                vis[c.first][i]=1;
            }
            else{
                q.push({c.first,i+1});
                break;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans+=vis[i][j];
    cout<<ans<<endl;
    return 0;
}
