#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll=long long;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int ops=0;
    vector<int> c(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]!=c[j]){
                if(j>=0)c[j-1]=1-c[j-1];
                c[j]=1-c[j];
                if(j<n-1)c[j+1]=1-c[j+1];
                ops++;
            }
        }
    }
    cout<<ops<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}