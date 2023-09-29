#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll a,b;cin>>a>>b;
    ll ansa=1;
    ll tmp=b;
    while(tmp--){
        ansa*=a;
    }
    tmp=a;
    ll ansb=1;
    while(tmp--){
        ansb*=b;
    }
    cout<<ansa+ansb<<endl;
    return  0;
}