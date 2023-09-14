#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll=long long;

void solve(){
    int x,y,n;
    cin>>x>>y>>n;
    vector<int> ans;
    ans.push_back(y);
    for(int i=1;i<n;i++){
        ans.push_back(ans.back()-i);
    }
    if(ans.back()<x){
        cout<<-1<<endl;
        return;
    }
    cout<<x<<" ";
    for(int i=n-2;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}