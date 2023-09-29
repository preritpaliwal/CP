#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    string s;cin>>s;
    for(int i=1;i<(int)s.size();i++){
        if(s[i]>=s[i-1]){cout<<"No\n";return;}
    }
    cout<<"Yes\n";
    return ;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
