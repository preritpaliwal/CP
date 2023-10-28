#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class Node{
    public:
    ll sum{};
    ll lazysum{};
    ll lazyset{};
};

vector<Node> t;
ll n;
vector<ll> v;

Node merge(const Node& n1,const Node& n2){
    Node n;
    n.sum=n1.sum+n2.sum;
    return n;
}

void build(ll nn,ll l,ll r){
    if(l==r){
        t[nn].sum=v[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(nn<<1,l,mid);
    build(nn<<1|1,mid+1,r);
    t[nn]=merge(t[nn<<1],t[nn<<1|1]);
}

void push(ll nn,ll l,ll r){
    if(t[nn].lazyset){
        t[nn].sum=(r-l+1)*t[nn].lazyset;
        if(l!=r){
            t[nn<<1].lazyset=t[nn].lazyset;
            t[nn<<1|1].lazyset=t[nn].lazyset;
            t[nn<<1].lazysum=0;
            t[nn<<1|1].lazysum=0;
        }
        t[nn].lazyset=0;
    }
    if(t[nn].lazysum){
        t[nn].sum+=(r-l+1)*t[nn].lazysum;
        if(l!=r){
            t[nn<<1].lazysum+=t[nn].lazysum;
            t[nn<<1|1].lazysum+=t[nn].lazysum;
        }
        t[nn].lazysum=0;
    }
    
}

void update(ll nn, ll l,ll r,ll ql,ll qr,ll ty,ll x){
    push(nn,l,r);
    if(qr<l || r<ql)return;
    if(ql<=l && r<=qr){
        if(ty==1){
            t[nn].lazysum+=x;
        }
        else{
            t[nn].lazyset=x;
            t[nn].lazysum=0;
        }
        push(nn,l,r);
        return;
    }
    ll mid=(l+r)>>1;
    update(nn<<1,l,mid,ql,qr,ty,x);
    update(nn<<1|1,mid+1,r,ql,qr,ty,x);
    t[nn]=merge(t[nn<<1],t[nn<<1|1]);
}

Node query(ll nn,ll l,ll r,ll ql,ll qr){
    if(qr<l || r<ql)return Node();
    push(nn,l,r);
    if(ql<=l && r<=qr)return t[nn];
    ll mid=(l+r)>>1;
    return merge(query(nn<<1,l,mid,ql,qr),query(nn<<1|1,mid+1,r,ql,qr));
}

int main(){
    cin>>n;ll q;cin>>q;t.resize(4*n+4);
    v.assign(n,0);for(ll i=0;i<n;i++)cin>>v[i];
    build(1,0,n-1);
    while(q--){
        ll t,l,r;cin>>t>>l>>r;
        if(t==3){
            cout<<query(1,0,n-1,l-1,r-1).sum<<"\n";
        }
        else{
            ll x;cin>>x;
            update(1,0,n-1,l-1,r-1,t,x);
        }
    }
}

