#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
vector<int> v;
vector<ll> t;

void build(int id,int l,int r){
    if(l==r){
        t[id]=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=t[2*id]+t[2*id+1]+0LL;
}

void update(int id,int l,int r,int pos,int x){
    if(l>pos || r<pos){
        return;
    }
    if(l==r){
        v[pos]+=x;
        t[id]+=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,x);
    update(2*id+1,mid+1,r,pos,x);
    t[id]=t[id*2]+t[2*id+1]+0LL;
}

ll query(int id,int l,int r,int ql,int qr){
    if(l>qr || r<ql){
        return 0LL;
    }
    if(ql<=l && r<=qr){
        return t[id];
    }
    int mid=(l+r)/2;
    return query(2*id,l,mid,ql,qr)+query(2*id+1,mid+1,r,ql,qr)+0LL;
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
    for(int i=n;i>0;i--){
        v[i]-=v[i-1];
    }
    // cerr<<"here\n";
    build(1,1,n);
    // cerr<<"built\n";
    for(int i=0;i<q;i++){
        int ch;cin>>ch;
        // cerr<<i<<endl;
        if(ch==1){
            int l,r,x;cin>>l>>r>>x;
            update(1,1,n,l,x);
            update(1,1,n,r+1,-x);
        }
        else{
            int k;cin>>k;
            cout<<query(1,1,n,1,k)<<endl;
        }
    }
}