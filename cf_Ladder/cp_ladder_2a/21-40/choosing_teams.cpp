// link to ques : https://codeforces.com/problemset/problem/432/A

#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int main()
{
    int n,k,z=0;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        v[i] = 5-v[i];
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 2;i<n;i+=3){
        if(v[i]>=k){
            z++;
        }
    }
    cout<<z;
    return 0;
}