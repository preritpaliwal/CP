#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<int> t;

void build(int id,int l,int r){
    if(l==r){
        t[id]=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id] = min(t[2*id],t[2*id+1]);
}

void update(int id,int l,int r,int pos, int x){
    if(l>pos || r<pos){
        return;
    }
    if(l==r && pos==l){
        t[id] = x;
        v[pos] = x;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,x);
    update(2*id+1,mid+1,r,pos,x);
    t[id] = min(t[2*id],t[2*id+1]);
}

int query(int id,int l,int r,int ql,int qr){
    if(l>qr || r<ql){
        return 1e9;
    }
    if(ql<=l && r<=qr){
        return t[id];
    }
    int mid=(l+r)/2;
    return min(query(2*id,l,mid,ql,qr),query(2*id+1,mid+1,r,ql,qr));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    v.resize(n+1,0);
    t.resize(4*(n+1),0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int ch,l,r;cin>>ch>>l>>r;
        if(ch==1){
            update(1,1,n,l,r);
        }
        else{
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}