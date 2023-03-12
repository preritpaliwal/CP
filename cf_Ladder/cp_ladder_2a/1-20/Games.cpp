// link to ques : https://codeforces.com/problemset/problem/268/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][2];
    for(int i = 0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }

    int k  = 0;

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i][0]==a[j][1]){
                k++;
            }
            if(a[j][0]==a[i][1]){
                k++;
            }
        }
    }
    cout<<k;
    return 0;
}