#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    // if(n<m){
    //     cout<<"NO\n";
    //     return;
    // }
    // if(n%m==0){
    //     cout<<"NO\n";
    //     return;
    // }
    vector<int> factors;
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            factors.push_back(i);
            if(i*i!=n){
                factors.push_back(n/i);
            }
        }
    }

    for(int i = 0;i<factors.size();i++){
        if(factors[i]==1){
            continue;
        }
        if(m>=factors[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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