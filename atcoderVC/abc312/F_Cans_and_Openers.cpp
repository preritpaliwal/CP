#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
vector<ll> v[3];
int main(){
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        ll t,x;cin>>t>>x;
        v[t].push_back(x);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    reverse(v[0].begin(),v[0].end());
    reverse(v[1].begin(),v[1].end());
    reverse(v[2].begin(),v[2].end());
    ll nt0=v[0].size();ll ans=0;
    for(ll i=1;i<nt0;i++)v[0][i]+=v[0][i-1];
    ll tmp2=0,avail=0,canidx=-1,openidx=-1;
    for(ll cnt=m;cnt>=0;cnt--){
        ll tmp=0;
        if(cnt!=0 && !v[0].empty())tmp=v[0][min(cnt-1,nt0-1)];
        ans=max(ans,tmp+tmp2);
        if(avail==0){
            openidx++;
            if(openidx==v[2].size())break;
            avail=v[2][openidx];
        }
        else{
            canidx++;
            if(canidx==v[1].size())break;
            avail--;
            tmp2+=v[1][canidx];
        }
    }
    cout<<ans<<endl;
}