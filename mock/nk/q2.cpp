#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void update(int i,int j, set<pair<int,pair<int,int>>> &s,vector<vector<int>> &v){
    int di[]={0,1,0,-1};
    int dj[]={1,0,-1,0};
    for(int i=0;i<4;i++){
        int curi=di[i]+i;
        int curj=dj[i]+j;
        if(curi<0 || curj<0 || curi>=v.size() || curj>=v[0].size())continue;
        int old=v[curi][curj];
        if(old<9){
            s.erase({old,{curi,curj}});
            s.insert({old-1,{curi,curj}});
            v[curi][curj]=old-1;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;cin>>n>>m;
    vector<string> v(n);
    for(auto &i:v)cin>>i;
    set<pair<int,pair<int,int>>> deg;
    vector<vector<int>> degr(n,vector<int> (m,10));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='X')continue;
            int d=0;
            if(i!=0) d+=(v[i-1][j]=='O');
            if(i!=n-1) d+=(v[i+1][j]=='O');
            if(j!=0) d+= (v[i][j-1]=='O');
            if(j!=m-1) d+=(v[i][j+1]=='O');
            deg.insert({d,{i,j}});
            degr[i][j]=d;
        }
    }
    int ans=0;
    while(!deg.empty()){
        auto it = deg.begin();
        int d=it->first;
        int ni=it->second.first;
        int nj=it->second.second;
        deg.erase(it);
        int mini=ni,minj=nj;
        degr[ni][nj]=10;
        if(ni!=0){
            if(degr[ni-1][nj]<degr[mini][minj]){
                mini=ni-1;
                minj=nj;
            }
        }
        if(nj!=0){
            if(degr[ni][nj-1]<degr[mini][minj]){
                mini=ni;
                minj=nj-1;
            }
        }
        if(nj!=m-1){
            if(degr[ni][nj+1]<degr[mini][minj]){
                mini=ni;
                minj=nj+1;
            }
        }
        if(ni!=n-1){
            if(degr[ni+1][nj]<degr[mini][minj]){
                mini=ni+1;
                minj=nj;
            }
        }
        if(degr[mini][minj]>5){
            continue;
        }
        ans++;
        deg.erase({degr[mini][minj],{mini,minj}});
        degr[mini][minj]=10;
        update(mini,minj,deg,degr);
        update(ni,nj,deg,degr);
    }
    cout<<ans<<"\n";
    return 0;
}