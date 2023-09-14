#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int main(){
    int n,m;cin>>n>>m;
    vector<string> mat(n);
    for(int i=0;i<n;i++)cin>>mat[i];
    vector<vector<ll>> ans(n,vector<ll> (m,0));
    ans[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]=='.'){
                if(j+1<m){
                    ans[i][j]=(ans[i][j]+ans[i][j+1])%mod;
                }
                if(i+1<n){
                    ans[i][j]=(ans[i][j]+ans[i+1][j])%mod;
                }
            }
        }
    }
    cout<<ans[0][0]<<endl;
}