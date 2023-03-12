// link to ques : https://codeforces.com/problemset/problem/25/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    vector<int> dif(n-1,0);
    for(int i  =0;i<n;i++){
        cin>>v[i];
        if(i!=0){
            dif[i-1] = v[i] - v[i-1];
        }
    }
    for(int i = 1;i<n-1;i++){
        if(dif[i-1]%2 && dif[i]%2){
            cout<<i+1;
            return 0;
        }
    }
    if(dif[0]%2){
        cout<<1;
    }
    else{
        cout<<n;
    }
    return 0;
}