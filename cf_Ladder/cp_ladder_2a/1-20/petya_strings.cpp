// link to ques : 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "AB",s2 = "ABD";
    // cin>>s1>>s2;
    // transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    // transform(s2.begin(),s2.end(),s2.begin(),::toupper);
    if(s1>s2){
        cout<<1;
    }
    else if(s1==s2){
        cout<<0
;    }
else{
    cout<<-1;
}
    return 0;
}