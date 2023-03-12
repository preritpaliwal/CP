#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int a = 0;
        int b = INT_MAX;
        for(int &i:v){
            cin>>i;
            a = a|i;
            b = b&i;
        }
        cout<<a-b<<endl;;
    }
}