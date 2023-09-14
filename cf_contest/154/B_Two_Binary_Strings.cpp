#include <bits/stdc++.h>
using namespace std;
using ll=long long;


void solve(){
    string a[2];cin>>a[0]>>a[1];
    int n=a[0].size();
    for(int i=1;i<n;i++){
        if(a[0][i]==a[1][i] && a[0][i-1]==a[1][i-1]){
            if(a[0][i-1]=='0' && a[1][i]=='1'){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
}