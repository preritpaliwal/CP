#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> c;
vector<double> e;
int main(){
    cin>>n>>m;c.resize(n);e.resize(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        ll tot,sum=0;cin>>tot;
        for(int j=0;j<tot;j++){
            int tmp;cin>>tmp;sum+=tmp;
        }
        e[i]=((double)sum)/tot;
    }
    ll l=0,r=1e9,ans=r;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<
    return 0;
}