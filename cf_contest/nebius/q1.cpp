#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    int a,b;
    cin>>a>>b;
    a = abs(a);
    b = abs(b);
    int alt = min(a,b);
    int rem = (max(a,b)-alt);
    if(rem==0){
    cout<<2*alt<<endl;
    }
    else{
        cout<<2*alt+rem*2 -1<<endl;;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}