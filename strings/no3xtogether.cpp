// link to ques : https://codeforces.com/problemset/problem/978/B

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=0;
    string s;
    cin>>n>>s;
    for(int i = 0;;i++)
    {
        if(s.begin() + i+2 == s.end() )
        {
            break;
        }
        if(s[i]==s[i+1] && s[i+1]==s[i+2] && s[i+2]=='x')
        {
            s.erase(i+1,1);
            // cout<<s<<"  ";
            i--;
            k++;
        }
    }
    cout<<k;
    return 0;
}