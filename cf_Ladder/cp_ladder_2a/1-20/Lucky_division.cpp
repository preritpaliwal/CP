// link to ques : https://codeforces.com/problemset/problem/122/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int a[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    for(i = 0;i<14;i++){
        if(!(n%a[i])){
            break;
        }
    }
    if(i==14){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}