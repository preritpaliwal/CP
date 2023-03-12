// link to ques : https://codeforces.com/problemset/problem/1138/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    v.push_back(0);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            if(a[i]!=a[i-1])
            {
                v.push_back(i);
            }
        }
    }
    v.push_back(n);
    int s =0;
    for(int i = 0;i<v.size()-2;i++)
    {
        int k = min(v[i+1]-v[i],v[i+2]-v[i+1]);
        if(k>s)
        {
            s = k;
        }
    }
    cout<<2*s;
    return 0;
}