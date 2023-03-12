// link to ques : https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a[(s.size()+1)/2];
    for(int i = 0;i<s.size();i++)
    {
        if(i%2==0)
        {
            a[(i/2)] = s[i] ;
            // cout<<a[(i/2)]<<" ";
        }
    }
    sort(a,a+(s.size()+1)/2);
    for(int i = 0;i<s.size();i++)
    {
        if(i%2==0)
        {
             s[i] = a[i/2];
        }
    }
    cout<<s;
    return 0;
}