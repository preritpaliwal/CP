// link to ques : https://codeforces.com/problemset/problem/1481/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        string s;
        cin>>x>>y>>s;
        map<char,int> m;
        m.insert(make_pair('U',0));
        m.insert(make_pair('D',0));
        m.insert(make_pair('L',0));
        m.insert(make_pair('R',0));
        for(int i = 0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        // cout<<"u : "<<m['U']<<"\n";
        // cout<<"d : "<<m['D']<<"\n";
        // cout<<"r : "<<m['R']<<"\n";
        // cout<<"l : "<<m['L']<<"\n";
        int k;
        if(x>=0 )
        {
            if(y>=0)
            {
                if(x<=m['R'] && y<=m['U'])
                {
                    k = 1;
                }
                else
                {
                    k = 0;
                }
            }
            else
            {
                if(x<=m['R'] && (-y)<=m['D'])
                {
                    k = 1;
                }
                else
                {
                    k = 0;
                }
            }
        }
        else
        {
            if(y>=0)
            {
                if((-x)<=m['L'] && y<=m['U'])
                {
                    k = 1;
                }
                else
                {
                    k = 0;
                }
            }
            else
            {
                if((-x)<=m['L'] && (-y)<=m['D'])
                {
                    k = 1;
                }
                else
                {
                    k = 0;
                }
            }
        }
        if(k==1)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}