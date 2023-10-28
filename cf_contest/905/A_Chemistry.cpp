#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n,k;cin>>n>>k;string s;cin>>s;
    map<char,int> cnt;
    for(char c:s){
        cnt[c]++;
    }
    bool once=true;
    for(auto p:cnt){
        if(p.second%2==1 && once){
            once=false;
        }
        else if(p.second%2==1 && !once){
            k--;
        }
    }
    if(k>=0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return ;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}