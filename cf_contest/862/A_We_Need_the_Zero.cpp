#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    if(n%2==0){
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans ^= a[i];
        }
        if(ans==0){
            cout<<"0"<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    else{
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans ^= a[i];
        }
        cout<<ans<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}