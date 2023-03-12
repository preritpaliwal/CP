#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        int z = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        vector<int> v;
        int k = 1;
        while(v.size()!=n){
            for(int i = 0;i<n;i++){
                if(a[i]<= k*n && a[i]!=-1){
                    a[i] = -1;
                    v.push_back(i+1);
                }
            }
            k++;
        }
        for(int i = 0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}