#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,k;
vector<int> v;

void solve(){
    cin>>n>>k;
    v.resize(n);
    vector<vector<int>> tmp(k);
    for(int i=0;i<k;i++){
        tmp[i].push_back(-1);
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
        tmp[v[i]-1].push_back(i);
    }
    for(int i=0;i<k;i++){
        tmp[i].push_back(n);
    }
    int ans=1e9;
    for(int i=0;i<k;i++){
        int max1=0,max2=0;
        for(int j=1;j<tmp[i].size();j++){
            int cur=tmp[i][j]-tmp[i][j-1]-1;
            if(cur>max1){
                max2=max1;
                max1=cur;
            }
            else if(cur>max2){
                max2=cur;
            }
        }
        ans=min(ans,max(max1/2,max2));
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}