// link to ques : https://codeforces.com/problemset/problem/479/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> r{a*b*c, a + b*c, a*b + c, (a+b)*c, a*(b+c),a+b+c};
    cout<<*max_element(r.begin(),r.end());
    return 0;
}