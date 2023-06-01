#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    for(int l=0;l<=n;l++){
        int curl = 0;
        for(int i = 0;i<n;i++){
            if(v[i]>l){
                curl++;
            }
        }
        if(curl==l){
            cout<<curl<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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