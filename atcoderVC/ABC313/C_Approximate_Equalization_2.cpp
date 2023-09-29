#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,sum=0;cin>>n;vector<ll> v(n);for(ll &i:v){cin>>i;sum+=i;}
    ll val=sum/n;
    ll rem=sum%n;
    ll ops=0;
    sort(v.begin(),v.end());
    for(ll i=n-1;i>=0;i--){
        if(rem==0){
            ops+=abs(val-v[i]);
        }
        else{
            ops+=abs(val+1-v[i]);
            rem--;
        }
    }
    cout<<ops/2<<endl;
}
