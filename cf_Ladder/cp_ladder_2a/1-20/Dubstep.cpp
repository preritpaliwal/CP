// link to ques : https://codeforces.com/problemset/problem/208/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string k = "WUB";
    string ans;
    for(int i = 0;i<s.size();i++){
        // cout<<"i : "<<i<<endl;
        string cur = s.substr(i,3);
        // cout<<"cur = "<<cur<<endl;
        if(cur==k){
            if(ans.size()!=0){
                ans += " ";
            }
            i+=2;
            // cout<<"i = "<<i<<endl;
            continue;
        }
        ans += s[i];
        // cout<<"ans = "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}