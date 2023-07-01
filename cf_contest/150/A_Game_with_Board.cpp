#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n>4){
        cout<<"Alice\n";
    }
    else{
        cout<<"Bob\n";
    }
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