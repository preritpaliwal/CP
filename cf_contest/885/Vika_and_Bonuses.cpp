#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll s,k;
ll val(ll x){
    return (s+(x)*20)*(k-x*4);
}

ll search(){
    if(k<=0){
        return 0;
    }
    ll l=0,r=k/4;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        ll dif=val(mid+1)-val(mid);
        if(dif>=0){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    return max(val(ans),val(ans+1));
    // ll x=min((5*k-s)/40,k/4);
    // return max(s*k,max(val(max(0LL,x)),val(min(k/4,max(0LL,x+1)))));
    
}

void solve(){
    fastio
    cin>>s>>k;
    if(s%10==0){
        cout<<s*k<<endl;
    }
    else if(s%10==5){
        ll sn=s+5;
        cout<<max(s*k,sn*(k-1))<<endl;;
    }
    else{
        ll d=s%10;
        ll ans=s*k;
        if(d%2==1){
            s+=d;
            k--;
        }
        for(int i=0;i<4;i++){
            ans=max(ans,search());
            s+=s%10;
            k--;
        }
        cout<<ans<<endl;
    }

    return;
}

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}