#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> l;
bool check(ll w){
    ll lines=0,idx=0;
    while(true){
        ll cur=l[idx];
        while(true){
            if(cur<=w){
                idx++;
            }
            else{
                break;
            }
            if(idx==n){
                break;
            }
            cur+=(1+l[idx]);
        }
        lines++;
        if(lines>m)return false;
        if(idx==n){
            break;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;l.resize(n);for(ll& i:l)cin>>i;
    ll l=1,r=1e18,ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}