// link to ques : 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s0,s1,s2;
    getline(cin,s0);
    getline(cin,s1);
    getline(cin,s2);
    stringstream ss(s0);
    ss>>n;
    vector<bool> v(n,false);
    int z = 0;
    for(char i : s2){
        if(i==' '){
            continue;
        }
        if(!v[i-'0']){
            v[i-'0'] = true;
            z++;
        }
    }

    for(char i : s1){
        if(i==' '){
            continue;
        }
        if(!v[i-'0']){
            v[i-'0'] = true;
            z++;
        }
    }
    
    if(z==n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}