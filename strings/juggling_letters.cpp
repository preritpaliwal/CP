// link to ques : https://codeforces.com/problemset/problem/1397/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        map <char,int> m;
        for(int i =0;i<26;i++)
        {
            char c = 97+i;
            m.insert(make_pair(c,0));
            // cout<<c<<" : "<<m[c]<<"\n";
        }
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            for(int j = 0;j<s[i].size();j++)
            {
                m[s[i][j]]++;
                // cout<<s[i][j]<<" : "<<m[s[i][j]]<<" ";
            }
            // cout<<"\n";
        }
        int k = 0;
        for(int i =0;i<26;i++)
        {
            char c = 97+i;
            // cout<<c<<" : "<<m[c]<<"\n";
            if(m[c]%n != 0)
            {
                k=1;
                break;
            }
        }
        if(k ==0 )
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }

    return 0;

}