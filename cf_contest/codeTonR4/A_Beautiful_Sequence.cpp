#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    for(int i =0 ;i<n;i++){
        if(v[i]<=i+1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO\n";
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