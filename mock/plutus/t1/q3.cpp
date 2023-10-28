#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,x;cin>>n>>x;vector<ll> a(n);
    int mini=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<a[mini])mini=i;
    }
    int idx=(mini+1)%n;
    ll ans=0;
    for(int i=0;i<n;i++){
        a[idx]=min(a[idx],a[(idx-1+n)%n]+x);
        ans+=a[idx];
        idx=(idx+1)%n;
    }
    cout<<ans<<"\n";
}