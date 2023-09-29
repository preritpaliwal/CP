#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;vector<vector<char>> v(n,vector<char> (m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    vector<vector<int>> take(n,vector<int> (m,1));
    while(true){
        bool updated=false;
        vector<vector<int>> taken=take;
        for(int i=0;i<n;i++){
            set<char> s;
            int cnt=0;
            for(int j=0;j<m;j++)if(take[i][j]==1){s.insert(v[i][j]);cnt++;}
            if(s.size()==1 && cnt!=1){
                updated=true;
                for(int j=0;j<m;j++)taken[i][j]=0;
            }
        }
        for(int j=0;j<m;j++){
            set<char> s;
            int cnt=0;
            for(int i=0;i<n;i++)if(take[i][j]==1){s.insert(v[i][j]);cnt++;}
            if(s.size()==1 && cnt!=1){
                updated=true;
                for(int i=0;i<n;i++)taken[i][j]=0;
            }
        }
        take=taken;
        if(!updated)break;
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans+=take[i][j];
    cout<<ans<<endl;
    return 0;
}