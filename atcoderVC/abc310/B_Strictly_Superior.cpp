#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> p;
vector<set<int>> f;
bool super(int ni,int nj){
    if(p[ni]>p[nj])return false;
    if(p[ni]==p[nj]){
        if(f[ni].size()<=f[nj].size())return false;
        for(auto it:f[nj])if(f[ni].find(it)==f[ni].end())return false;
        return true;
    }
    if(f[ni].size()<f[nj].size())return false;
    for(auto it:f[nj])if(f[ni].find(it)==f[ni].end())return false;
    return true;
}
int main(){
    int n,m;cin>>n>>m;
    p.resize(n);
    f.resize(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        int a;cin>>a;
        for(int j=0;j<a;j++){int b;cin>>b;f[i].insert(b);}
        for(int j=0;j<i;j++){
            if(super(i,j) || super(j,i) ){
                cout<<"Yes\n";return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;
}