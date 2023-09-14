#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct no{
    int max1;
    int max2;
    no(){
        max1=0;
        max2=0;
    }
};

int n;
vector<int> v;
vector<struct no> t;

struct no merge(struct no n1, struct no n2){
    struct no tmp;
    if(n1.max1<n2.max1)swap(n1,n2);
    tmp.max1=n1.max1;
    tmp.max2=max(n2.max1,n1.max2);
    return tmp;
}

void build(int id,int l,int r){
    if(l==r){
        t[id].max1=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){t[id].max1=val;return;}
    int mid=(l+r)>>1;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

struct no query(int id,int l,int r,int ql,int qr){
    if(ql>r || qr<l)return no();
    if(ql<=l && r<=qr)return t[id];
    int mid=(l+r)>>1;
    return merge(query(id<<1,l,mid,ql,qr),query(id<<1|1,mid+1,r,ql,qr));
}

int main(){
    fastio
    cin>>n;
    v.resize(n+1);
    t.resize(4*n);
    for(int i=1;i<=n;i++)cin>>v[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        char ch;
        int ql,qr;
        cin>>ch>>ql>>qr;
        if(ch=='U'){
            update(1,1,n,ql,qr);
        }
        else{
            struct no ans=query(1,1,n,ql,qr);
            cout<<ans.max1+ans.max2<<endl;
        }
    }
}