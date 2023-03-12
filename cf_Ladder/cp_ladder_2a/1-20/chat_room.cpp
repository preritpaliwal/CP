// link to ques : https://codeforces.com/problemset/problem/58/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string h = "hello";
    int j = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]==h[j]){
            j++;
        }
        if(j==5){
            break;
        }
    }
    if(j==5){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}