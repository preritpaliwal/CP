// link to ques : https://codeforces.com/contest/776/problem/B

#include <bits/stdc++.h>
using namespace std;
int get_largest_factor(int a){
    for(int i = 2;i<=sqrt(a);i++){
        if(a%i==0){
            return a/i;
        }
    }
    return -1;
}

void prime(int n){
    int a[n+1];
    for(int i = 0;i<=n;i++){
        a[i] = i;
    }
    for(int i = 2;i<=n;i++){
        if(a[i]==i){
            for(int j = i;j<=n;j+=i){
                a[j] = i;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if(a[i]==i){
            cout<<i<<" ";
        }
    }
}



int main()
{
    int n;
    cin>>n;
    int a[n];
    // int k = 2;
    cout<<n/2<<endl;
    for(int i = 0;i<n;i++)
    {
        int q = get_largest_factor(i+2);
        if(q==-1){
            a[i]=1;
        }
        else {
            a[i] = a[q-2] + 1;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}