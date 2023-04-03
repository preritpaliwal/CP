#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m;
    cin>>m;
    vector<int> n(m);
    vector<vector<int>> a;
    map<int,int> mp;
    for(int i = 0;i<m;i++){
        cin>>n[i];
        vector<int> an(n[i]);
        for(int j =0;j<n[i];j++){
            cin>>an[j];
            mp[an[j]] = i;
        }
        a.push_back(an);
    }
    vector<int> ans;
    bool pos = true;
    for(int i = 0;i<m;i++){
        bool pushed = false;
        for(int j = 0;j<n[i];j++){
            if(mp[a[i][j]]==i){
                ans.push_back(a[i][j]);
                pushed=true;
                break;
            }
        }
        if(!pushed){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout<<-1<<endl;
        return;
    }
    for(int i:ans){
        cout<<i<<" ";
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