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
    int mid=1LL*(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id] = t[2*id] + t[2*id+1]+0LL;
}

void update(int id,int l,int r,int k,int x){
    if(l>k || r<k){
        return;
    }
    if(l==r && l==k){
        v[l] = x;
        t[id] = x;
        return;
    }
    int mid=1LL*(l+r)/2;
    update(2*id,l,mid,k,x);
    update(2*id+1,mid+1,r,k,x);
    t[id] = t[2*id]+t[2*id+1]+0LL;
}

ll query(int id,int l,int r,int ql,int qr){
    if(l>qr || r<ql){
        return 0;
    }
    else if(ql<=l && r<=qr){
        return t[id];
    }
    int mid=1LL*(l+r)/2;
    return query(2*id,l,mid,ql,qr)+query(2*id+1,mid+1,r,ql,qr)+0LL;
}

int main(){
    int q;
    cin>>n>>q;
    v.resize(n+1,0);
    t.resize(4*(n+1),0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int ch;cin>>ch;
        if(ch==1){
            int k,x;cin>>k>>x;
            update(1,1,n,k,x);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }

}