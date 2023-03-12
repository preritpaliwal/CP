// link to ques : https://codeforces.com/problemset/problem/451/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(min(m,n)%2){
        cout<<"Akshat";
    }
    else{
        cout<<"Malvika";
    }
    return 0;
}