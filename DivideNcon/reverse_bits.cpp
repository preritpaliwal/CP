// link to ques : https://leetcode.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int n;
    cin>>n;
    unsigned int a = 0;
    for(int i = 0;n!=0;i++){
        int k = n%10;
        n/=10;
        a+=pow(2,i)*k;
    }
    cout<<a;
    return 0;
}