#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int &i:v){
            cin>>i;
        }
        vector<int> pre(n);
        pre[0] = v[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]+v[i];
        }
        
    }
}