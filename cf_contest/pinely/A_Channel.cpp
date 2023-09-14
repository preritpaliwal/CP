#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    int n,a,q;
    cin>>n>>a>>q;
    string s;
    cin>>s;
    int maxon=a;
    int minon=a;
    for(char c:s){
        if(c=='+'){
            a++;
            minon++;
        }
        else{
            a--;
        }
        maxon=max(maxon,a);
    }
    if(maxon>=n){
        cout<<"YES\n";
    }
    else if(minon<n){
        cout<<"NO\n";
    }
    else {
        cout<<"MAYBE\n";
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