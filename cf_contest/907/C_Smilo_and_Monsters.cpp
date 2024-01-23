#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll fun(ll k,ll cnt){
    if(k<=3){
        return k;
    }
    else{
        return (k+1)/2 +1-cnt;
    }
}
void solve(){
    ll n;cin>>n;
    multiset<ll> ms;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ms.insert(a);
    }
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        v[i]=*ms.begin();
        ms.erase(ms.begin());
        // cerr<<v[i]<<" ";
    }
    // cerr<<"\n";
    ll ans=0;
    ll cnt=0;
    ll last=n-1;
    for(int i=0;i<=last;i++){
        if(i==last){
            if(v[i]==1){
                ans++;
                break;
            }
            else{
                ans += (v[i]-cnt+1)/2+1;
                break;
            }
        }
        if(cnt+v[i]<v[last]){
            ans+=v[i];
            cnt+=v[i];
            v[i]=0;
        }
        else if(cnt+v[i]>v[last]){
            ans+=v[last]-cnt+1;
            v[i]-=(v[last]-cnt);
            v[last]=0;
            last--;
            i--;
            cnt=0;
        }
        else{
            ans+=v[i]+1;
            v[i]=0;
            v[last]=0;
            last--;
            cnt=0;
        }
        // cerr<<ans<<" "<<cnt<<" "<<i<<" "<<last<<"\n";

    }
    // cerr<<"\n\n";
    cout<<ans<<"\n";

    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        // cerr<<t<<":\n";
        solve();
    }
    return 0;
}

