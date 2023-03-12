// link to ques : https://codeforces.com/problemset/problem/439/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,z;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        if(i!=0){
            v[i] += (10+v[i-1]);
        }
        cin>>z;
        v[i] += z;
    }
    if(v[n-1]>k){
        cout<<-1;
    }
    else{
        cout<<2*(n-1)+(k-v[n-1])/5;
    }

    return 0;
}