//link to ques : https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s.size()>10)
        {
            if(s.size()==11)
            {
                string t = {s[0],'9',s[s.size()-1]};
                v.push_back(t);
            }
            else
            {
                char d1 = (s.size()-2)/10  + 48;     
                char d2 = (s.size()-2)%10  + 48;
                string t = {s[0],d1,d2,s[s.size()-1]};
                v.push_back(t);
            }
        }
        else
        v.push_back(s);
    }
    for(int i = 0;i<n;i++)
    {
        cout<<v[i]<<"\n";
    }

    return 0;

}