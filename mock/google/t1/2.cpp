#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll t[(int)8e5+8];

void update(ll nn, ll l, ll r, ll val){
    // cerr<<"U>> "<<nn<<" "<<l<<" "<<r<< " "<<val<<endl;
    if(val<l || r<val)return;
    if(l==r){t[nn]++;return;}
    ll mid=(l+r)>>1;
    update(nn<<1,l,mid,val);
    update(nn<<1|1,mid+1,r,val);
    t[nn]=t[nn<<1]+t[nn<<1|1];
}

ll query(ll nn, ll l,ll r,ll ql,ll qr){
    // cerr<<"Q>> "<<nn<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
    if(qr<l || r<ql)return 0;
    if(ql<=l && r<=qr)return t[nn];
    ll mid=(l+r)>>1;
    return query(nn<<1,l,mid,ql,qr)+query(nn<<1|1,mid+1,r,ql,qr);
}

void solve(){
    int n;cin>>n; string s;cin>>s;
    int cnt=0;
    ll ans=0;
    update(1,0,2*n+1,n);
    for(int i=0;i<n;i++){
        if(s[i]=='1')cnt++;
        else cnt--;
        ans+=query(1,0,2*n+1,0,n+cnt-1);
        // cerr<<"i= "<<i<<", ans= "<<ans<<endl;
        update(1,0,2*n+1,n+cnt);
        // for(int i=0;i<4*n;i++){
        //     cerr<<i<<":"<<t[i]<<"\t";
        // }cerr<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}