// link to ques : https://codeforces.com/problemset/problem/71/A

#include <bits/stdc++.h>
using namespace std;
string tolower(string s)
{
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]<96)
        {
            s[i] = s[i] - ('A' - 'a');
        }
    }
    return s;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()-s2.size()>0)
    {
        cout<<1;
    }
    else if(s1.size()-s2.size()<0)
    {
        cout<<-1;
    }
    else{
        s1 = tolower(s1);
        s2 = tolower(s2);
        // cout<<s1<<" "<<s2<<"\n";
        int k = 0;
        for(int i = 0;i<s1.size();i++)
        {
            if(s1[i]>s2[i])
            {
                k = 1;
                break;
            }
            else if(s1[i]<s2[i])
            {
                k = -1;
                break;
            }
        }
        cout<<k;
    }    
    return 0;
}