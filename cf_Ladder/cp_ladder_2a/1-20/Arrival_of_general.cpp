// link to ques : https://codeforces.com/problemset/problem/144/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int i_max = 0,i_min = 0,max = a[0],min = a[0];
    for(int i = 1;i<n;i++){
        if(a[i]>max){
            max = a[i];
            i_max = i;
        }
        if(a[i]<=min){
            min = a[i];
            i_min = i;
        }
    }
    
    if(i_max<i_min){
        cout<<i_max+n-1-i_min;
    }
    else{
        cout<<i_max+n-2-i_min;
    }
    return 0;
}