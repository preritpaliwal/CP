#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;
    ll taste[2];
    taste[0]=taste[1]=0;
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        if(x==0){
            taste[0]=max(taste[0],max(y+taste[0],y+taste[1]));
        }
        else{
            taste[1]=max(taste[1],y+taste[0]);
        }
    }
    cout<<max(taste[1],taste[0])<<endl;
    return 0;
}