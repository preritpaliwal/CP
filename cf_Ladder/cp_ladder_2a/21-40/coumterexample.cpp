// link to ques : https://codeforces.com/problemset/problem/483/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

void print(ll a,ll b,ll c){
    cout<<a<<" "<<b<<" "<<c;
}

int main()
{
    ll l,r;
    cin>>l>>r;
    if(r-l<=1){
        cout<<-1;
    }
    else if(r-l==2){
        if(l%2==0)
        print(l,l+1,l+2);
        else{
            cout<<-1;
        }
    }
    else{
        if(l%2){
            print(l+1,l+2,l+3);
        }
        else{
            print(l,l+1,l+2);
        }
    }
    return 0;
}