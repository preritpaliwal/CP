#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int>> col(m+1);
    for(int i=0;i<n;i++){
        int a;cin>>a;col[a].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int cur=s[col[i].back()];
        for(int j=(int)col[i].size()-1;j>0;j--){
            s[col[i][j]]=s[col[i][j-1]];
        }
        s[col[i][0]]=cur;
    }
    cout<<s<<endl;
    return 0;
}