#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    if(v[0]==1){
        v[0] = 2;
    }
    for(int i = 1;i<n;i++){
        if(v[i]%v[i-1]==0){
            v[i]++;
        }
        if(v[i]==1){
            v[i]++;
            i--;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}