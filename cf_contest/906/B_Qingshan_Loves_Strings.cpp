#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m;cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int zz=0,oo=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            if(s[i]=='0'){
                zz++;
            }
            else{
                oo++;
            }
        }
    }
    if(zz == 0 && oo == 0){
        cout<<"Yes\n";
        return;
    }
    else if(zz > 0 && oo > 0){
        cout<<"No\n";
        return;
    }
    int good=1;
    for(int i=0;i<m-1;i++){
        if(t[i]==t[i+1]){
            good=0;
            break;
        }
    }
    if(good==0){
        cout<<"No\n";
        return;
    }
    if(t[0]!=t[m-1]){
        cout<<"No\n";
        return;
    }
    if(t[0]=='0' && zz==0){
        cout<<"Yes\n";
        return;
    }
    if(t[0]=='1' && oo==0){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
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