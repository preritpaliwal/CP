// link to ques : https://codeforces.com/problemset/problem/466/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(m*a>b){
        int c = min((n%m)*a + (n/m)*b,(n/m)*b + ((n%m) ? b : 0));
        cout<<c;
    }
    else{
        cout<<n*a;
    }
    return 0;
}