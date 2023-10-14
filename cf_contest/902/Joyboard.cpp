#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m,k;cin>>n>>m>>k;
    // map<ll,ll> mp;
    // for(ll x=0;x<=m;x++){
    //     ll y=x;
    //     set<ll> s;
    //     s.insert(y);
    //     for(ll i=n;i>=1;i--){
    //         s.insert(y%i);
    //         y%=i;
    //     }
    //     // cerr<<"x= "<<x<<" "<<s.size()<<"\n";
    //     mp[s.size()]++;
    // }
    
    // cerr<<endl;
    if(k>3){
        cout<<0<<"\n";
        return;
    }
    // cout<<mp[k]<<" ";
    if(k==3){
        if(m<=n){
            cout<<0<<"\n";
        }
        else{
            ll cnt=m/n;
            cout<<m-n-cnt+1<<"\n";
        }
        return;
    }
    if(k==2){
        cout<<min(m,n + m/n - 1)<<"\n";
    }
    else{
        cout<<1<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}