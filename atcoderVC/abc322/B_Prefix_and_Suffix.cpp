#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    bool pre=true;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])pre=false;
    }
    bool suf=true;
    for(int i=0;i<n;i++){
        if(s[n-1-i]!=t[m-i-1]){
            suf=false;
        }
    }
    if(pre && suf){
        cout<<0<<endl;
    }
    else if(pre){
        cout<<1<<endl;
    }
    else if(suf){
        cout<<2<<endl;
    }
    else {
        cout<<3<<endl;
    }
    return 0;
}