#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
ll n,k;
vector<ll> v;

bool check(ll maxh){
    for(int i=1;i<=n;i++){
        ll curh=maxh;
        ll cost=0;
        bool sat=false;
        for(int j=i;j<=n;j++){
            if(v[j]>=curh){
                sat=true;
                break;
            }
            cost+=curh-v[j];
            curh--;
        }
        if(sat){
            if(cost<=k){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin>>n>>k;
    v.resize(n+1,0);
    for(ll i=1;i<=n;i++)cin>>v[i];
    // ll ans=0;
    // for(ll idx=1;idx<=n;idx++){
    //     ll curmax=v[idx];
    //     ll curk=k;
    //     vector<ll> tmp{v[idx]};
    //     for(ll i=idx-1;i>0;i--){
    //         if(v[i]>tmp.back()){
    //             break;
    //         }
    //         else{
    //             if(curk>=tmp.back()+1-v[i]){
    //                 curk-=-v[i]+1+tmp.back();
    //                 tmp.push_back(tmp.back()+1);
    //                 curmax=max(curmax,tmp.back());
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     ans=max(curmax,ans);
    // }
    // cout<<ans<<endl;
    ll l=1,r=1e9;
    ll ans=l;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    fastio
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}