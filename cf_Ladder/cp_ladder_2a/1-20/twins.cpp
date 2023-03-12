// link to ques : https://codeforces.com/problemset/problem/160/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int total = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
    sort(a,a+n);
    int t = 0;
    int i;
    for(i = n-1;i>-1;i--){
        t+=a[i];
        if(t>total/2){
            break;
        }
    }
    cout<<n-i;
    return 0;
}