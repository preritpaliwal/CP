#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    cin>>x>>y;
    vector<int> xi(k),yi(k);
    bool isPos=true;
    for(int i=0;i<k;i++){
        cin>>xi[i]>>yi[i];
        if((x+y)%2==(xi[i]+yi[i])%2)isPos=false;
    }
    if(isPos)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}