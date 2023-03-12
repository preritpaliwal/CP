// link to ques : https://codeforces.com/problemset/problem/337/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i = 0;i<m;i++){
        cin>>a[i];
    }
    sort(a,a+m);
    // for(int i = 0;i<m;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int k = INT_MAX;
    for(int i = n-1;i<m;i++){
        // cout<<"diff = "<<a[i]-a[i-n+1]<<endl;
        if(k>(a[i]-a[i-n+1])){
            k = a[i]-a[i-n+1];
        }
        // cout<<k<<endl;
    }
    cout<<k;
    return 0;
}