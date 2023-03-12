// link to ques : https://codeforces.com/problemset/problem/313/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>0){
        cout<<n;
    }
    else{
        n*=-1;
        int a = (n)%10;
        n/=10;
        int b = (n)%10;
        if(b<a){
            cout<<-n;
        }
        else{
            cout<<-(n-b+a);
        }
    }
    return 0;
}