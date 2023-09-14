#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct no{
    int pre;
    long long less;
    no(){
        pre=0;
        less=0;
    }
};

int n;
vector<int> v;
vector<struct no> t;
map<int,int> mp;

struct no merge(struct no n1,struct no n2){
    struct no tmp;
    tmp.pre=n1.pre+n2.pre;
    tmp.less=n1.less+n2.less;
    return tmp;
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){
        t[id].pre=1;
        t[id].less=val;
        return;
    }
    int mid=(l+r)>>1;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}
struct no query(int id, int l,int r,int ql, int qr){
    if(qr<l||ql>r)return no();
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
    for(int i=1;i<=n;i++)mp[v[i]];
    int cnt=1;
    for(auto &it:mp)it.second=cnt++;
    long long ans=0;
    for(int i=n;i>0;i--){
        struct no tmp=query(1,1,n,1,mp[v[i]]-1);
        ans+=tmp.less;
        update(1,1,n,mp[v[i]],tmp.pre);
    }
    cout<<ans<<endl;
}