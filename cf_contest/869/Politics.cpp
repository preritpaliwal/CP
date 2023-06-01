#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    int ans = 1;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        if(i!=0){
            if(v[i]==v[0]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}