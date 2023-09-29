#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n;cin>>n;
    int s,e;cin>>s>>e;
    vector<pair<int,int>> p;
    int ans=s;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        if(a>=s && b>=e)ans=-1;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}