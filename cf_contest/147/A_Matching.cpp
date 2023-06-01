#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    if(s[0]=='0'){
            cout<<0<<endl;
            return;
    }
    int ans = 1;
    if(s[0]=='?'){
        ans = 9;
    }
    for(int i = 1;i<s.size();i++){
        if(s[i]=='?'){
            ans*=10;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}