// link to ques : https://codeforces.com/problemset/problem/4/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==2){
        cout<<"NO\n";
        return 0;
    }
    if(n%2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return 0;
}