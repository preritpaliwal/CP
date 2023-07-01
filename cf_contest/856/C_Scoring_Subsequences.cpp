#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int cur = 1;
    cout<<cur<<" ";
    for(int i = 1;i<n;i++){
        if(v[i-cur]>=cur+1){
            cur++;
        }
        cout<<cur<<" ";
    }
    cout<<endl;
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