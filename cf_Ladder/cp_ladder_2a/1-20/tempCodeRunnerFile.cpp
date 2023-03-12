// link to ques : https://codeforces.com/problemset/problem/318/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(2*k<=n){
        cout<<2*k -1;
    }
    else{
        cout<<2*(k-(n/2));
    }
    return 0;
}