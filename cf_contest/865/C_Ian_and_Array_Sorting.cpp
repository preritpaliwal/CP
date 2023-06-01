#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n-1);
    int a;
    cin>>a;
    for(int i = 0;i<n-1;i++){
        cin>>v[i];
        v[i] -= a;
        a = v[i]+a;
    }

    for(int i = 0;i<n-1;i++){
        if(i%2==1){
            
        }
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