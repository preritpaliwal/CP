#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int l = 1;
    int r = 2*n;
    int a[2][n];
    a[0][0] = r--;
    a[1][n-1] = r--;
    for(int i = 1;i<n;i++){
        if(i%2 == 1){
            a[0][i] = l++;
            a[1][i-1] = l++;
        }
        else{
            a[1][i-1] = r--;
            a[0][i] = r--;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<a[0][i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[1][i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}