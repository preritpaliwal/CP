// link to ques : https://codeforces.com/problemset/problem/443/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    set<char> se;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z'){
            se.insert(s[i]);
        }
    }
    cout<<se.size();
    return 0;
}