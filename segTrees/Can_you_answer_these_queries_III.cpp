#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Node{
    ll sum;
    ll rmax;
    ll lmax;
    ll ans;
    Node(){
        sum=0;
        rmax=-1e9;
        lmax=-1e9;
        ans=-1e9;
    }
};

void fill(struct Node &n, ll val){
    n.ans=n.lmax=n.rmax=n.sum=val;
}

ll n;
vector<ll> v;
vector<struct Node> t;

struct Node merge(struct Node n1, struct Node n2){
    struct Node tmp;
    tmp.sum = n1.sum+n2.sum;
    tmp.lmax = max(n1.lmax,n1.sum+n2.lmax);
    tmp.rmax = max(n1.rmax+n2.sum,n2.rmax);
    tmp.ans = max(max(n1.ans,n2.ans),n1.rmax+n2.lmax);
    return tmp;
}

void build(ll id,ll l,ll r){
    if(l==r){
        fill(t[id],v[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}

void update(ll id,ll l, ll r,ll pos,ll val){
    if(pos<l || r<pos){
        return;
    }
    if(l==r){
        fill(t[id],val);
        v[l] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[id*2],t[2*id+1]);
}

struct Node query(ll id,ll l,ll r,ll ql, ll qr){
    if(ql>r || qr<l){
        return Node();
    }
    if(ql<=l && r<=qr){
        return t[id];
    }
    ll mid=(l+r)/2;
    return merge(query(2*id,l,mid,ql,qr),query(2*id+1,mid+1,r,ql,qr));
}

void debug(){
    for(int i=0;i<2*n;i++){
        cerr<<t[i].sum<<" ";
    }
    cerr<<endl;
    for(int i=0;i<2*n;i++){
        cerr<<t[i].ans<<" ";
    }
    cerr<<endl;
    for(int i=0;i<2*n;i++){
        cerr<<t[i].lmax<<" ";
    }
    cerr<<endl;
    for(int i=0;i<2*n;i++){
        cerr<<t[i].rmax<<" ";
    }
    cerr<<endl;
    cerr<<"_______________\n\n";
}

int main(){
    fastio
    cin>>n;
    v.resize(n,0);
    t.resize(4*n);
    for(int i=0;i<n;i++)cin>>v[i];
    build(1,0,n-1);
    
    // debug();
    
    ll q;
    cin>>q;
    while(q--){
        ll ch,ql,qr;
        cin>>ch>>ql>>qr;
        if(ch==0){
            update(1,0,n-1,ql-1,qr);
            // debug();
        }
        else{
            cout<<query(1,0,n-1,ql-1,qr-1).ans<<endl;
        }
    }
}