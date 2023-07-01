#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(v[0]!=1){
        cout<<"NO\n";
        return;
    }
    // int lim = v[n-1]+1;
    // vector<int> tmp(lim,0);
    // tmp[0] = 1;
    // for(int check = 1;check<n;check++){
    //     vector<int> tmp2(lim,0);
    //     for(int j = 0;j<lim-v[check-1];j++){
    //         tmp2[j+v[check-1]] = tmp[j];
    //     }
    //     for(int j = 0;j<lim;j++){
    //         tmp[j] = tmp[j]|tmp2[j];
    //     }
    //     // cerr<<endl;
    //     if(tmp[v[check]]==0){
    //         cout<<"NO\n";
    //         return;
    //     }
    // }
    // cout<<"YES\n";
    long long sumTill = 1;
    for(int i = 1;i<n;i++){
        if(v[i]<=sumTill){
            sumTill += v[i];
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        // cerr<<"------------" <<endl;
    }
}