#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    if(n<m){cout<<0<<endl;return 0;}
    cout<<(n-m)/p + 1<<endl;return 0;
}