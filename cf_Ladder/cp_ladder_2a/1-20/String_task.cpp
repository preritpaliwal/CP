// link to ques : https://codeforces.com/problemset/problem/118/A

#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c,char v[]){
    for(int i = 0;i<6;i++){
        if(c==v[i] || c==(v[i]-'A'+'a')){
            return true;
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    string t;
    char vowels[6] = {'A','O','Y','E','U','I'};
    for(int i = 0;i<s.size();i++){
        if(isvowel(s[i],vowels)){
            continue;
        }
        t += ".";
        if(s[i]<95){
            t += s[i] - 'A' + 'a';
        }
        else{
            t += s[i];
        }
    }
    cout<<t;
    return 0;
}