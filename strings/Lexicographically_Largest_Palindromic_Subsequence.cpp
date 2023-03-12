// link to ques : https://codeforces.com/problemset/problem/202/A

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin>>s;
//     char max = '\0';
//     int count = 0;
//     for(int i = 0;i<s.size();i++)
//     {
//         if(s[i]>max)
//         {
//             count = 1;
//             max = s[i];
//         }
//         else if(s[i]==max)
//         {
//             count++;
//         }
//     }
//     for(int i = 0;i<count;i++)
//     {
//         cout<<max;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    cout<<s.substr(0,partition(s.begin(),s.end(),[&](char a){return a==*max_element(s.begin(),s.end());})-s.begin());
}