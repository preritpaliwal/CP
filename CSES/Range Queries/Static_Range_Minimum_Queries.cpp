#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> v;
vector<int> segtree;

void build(int id,int l,int r){
    if(l==r){
        segtree[id] = v[l];
        return;
    }
    int mid = 1LL*(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    segtree[id] = min(segtree[2*id],segtree[2*id+1]);
}

int query(int id,int l,int r,int ql,int qr){
    if(l>qr || r<ql){
        return 1e9;
    }
    else if(ql<=l && r<=qr){
        return segtree[id];
    }
    int mid = 1LL*(l+r)/2;
    return min(query(2*id,l,mid,ql,qr),query(2*id+1,mid+1,r,ql,qr));
}

int main(){
    fastio
    int n,q;
    cin>>n>>q;
    v.resize(n+1,0);
    segtree.resize(4*(n+1),0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int ql,qr;cin>>ql>>qr;
        cout<<query(1,1,n,ql,qr)<<endl;
    }
}