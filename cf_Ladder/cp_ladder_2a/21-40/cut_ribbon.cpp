// link to ques : https://codeforces.com/problemset/problem/189/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int maxribbon(int n,int a[],int memo[]){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n] = 1 + max(maxribbon(n-a[0],a,memo),max(maxribbon(n-a[1],a,memo),maxribbon(n-a[2],a,memo)));
    return memo[n];
}

int main()
{
    int n,a[3],memo[4010];
    for(int i = 0;i<4010;i++){
        memo[i]=-1;
    }
    cin>>n>>a[0]>>a[1]>>a[2];
    cout<<maxribbon(n,a,memo);
    return 0;
}