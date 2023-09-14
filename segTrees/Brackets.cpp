#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct no{
    int lcb;
    int rob;
    no(){
        lcb=0;
        rob=0;
    }
};

int n;
vector<char> v;
vector<struct no> t;

struct no merge(struct no n1, struct no n2){
    struct no tmp;
    tmp.lcb=n1.lcb+n2.lcb-min(n1.rob,n2.lcb);
    tmp.rob=n1.rob+n2.rob-min(n1.rob,n2.lcb);
    return tmp;
}

void build(int id,int l,int r){
    if(l==r){
        t[id].rob=((v[l]=='(')?1:0);
        t[id].lcb=((v[l]==')')?1:0);
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){swap(t[id].lcb,t[id].rob);return;}
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
    for(int cnt=1;cnt<=10;cnt++){
        cout<<"Test "<<cnt<<":\n";
        cin>>n;
        v.resize(n+1);
        t.resize(4*n);
        for(int i=1;i<=n;i++)cin>>v[i];
        build(1,1,n);
        int q;
        cin>>q;
        while(q--){
            int k;cin>>k;
            if(k>0){
                update(1,1,n,k,0);
            }
            else{
                if(t[1].lcb==0 && t[1].lcb==t[1].rob)cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}