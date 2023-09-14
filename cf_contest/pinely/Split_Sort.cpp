#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        p[i].second=i;
        cin>>p[i].first;
    }
    sort(p.begin(),p.end());
    int ans=0;
    for(int i=1;i<n;i++){
        if(p[i].second<p[i-1].second){
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}