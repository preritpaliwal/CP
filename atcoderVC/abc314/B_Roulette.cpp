#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;
    vector<vector<int>> bet(37);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
        for(int j=0;j<c[i];j++){
            int a;cin>>a;
            bet[a].push_back(i);
        }
    }
    int x;cin>>x;
    int minb=1e9;
    for(int i:bet[x]){
        minb=min(minb,c[i]);
    }
    if(minb>=1e9){cout<<0<<endl;return 0;}
    vector<int> ans;
    for(int i:bet[x]){
        if(minb==c[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" ";
    return 0;
}