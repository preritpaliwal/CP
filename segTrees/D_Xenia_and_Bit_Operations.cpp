#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct no{
    int val;
    bool useOR;
    no(){
        val=0;
        useOR=true;
    }
};

int n;
vector<int> v;
vector<struct no> t;

struct no merge(struct no n1, struct no n2){
    if(n1.useOR!=n2.useOR){
        cerr<<"Wrong level nodes merged\n"<<endl;return no();
    }
    struct no tmp;
    if(n1.useOR)tmp.val=n1.val|n2.val;
    else tmp.val=n1.val^n2.val;
    tmp.useOR=!n1.useOR;
    return tmp;
}

void build(int id,int l,int r){
    if(l==r){
        t[id].val=v[l];
        t[id].useOR=true;
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){t[id].val=val;return;}
    int mid=(l+r)>>1
    ;
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
    int q;
    cin>>n>>q;
    n=pow(2,n);
    v.resize(n+1);
    t.resize(4*n);
    for(int i=1;i<=n;i++)cin>>v[i];
    build(1,1,n);
    while(q--){
        int p,b;cin>>p>>b;
        update(1,1,n,p,b);
        cout<<t[1].val<<endl;
    }
}