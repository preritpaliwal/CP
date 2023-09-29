#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;vector<ll> v(n+1,0);vector<ll> ans(n+1,0);
    for(int i=0;i<3*n;i++){
        int a;cin>>a;
        v[a]++;
        if(v[a]==2){
            ans[a]=i;
        }
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[ans[i]]=i;
    }
    for(auto it:mp){
        cout<<it.second<<endl;
    }
    return 0;
}