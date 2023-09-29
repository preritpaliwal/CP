#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;vector<vector<int>> v(n,vector<int> (n,0));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){char c;cin>>c;v[i][j]=c=='1';}
    int cur=v[0][n-1];
    for(int i=n-1;i>0;i--){
        v[0][i]=v[0][i-1];
    }
    for(int i=0;i<n-1;i++){
        v[i][0]=v[i+1][0];
    }
    for(int i=0;i<n-1;i++){
        v[n-1][i]=v[n-1][i+1];
    }
    for(int i=n-1;i>0;i--){
        v[i][n-1]=v[i-1][n-1];
    }
    v[1][n-1]=cur;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}