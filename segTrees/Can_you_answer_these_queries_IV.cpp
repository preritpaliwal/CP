/*
THIS WAS A GOOD SOLUTION BUT DID NOT PASS TIME LIMIT


#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie();cout.tie();
using ll=long long;



struct Node{
    ll vals[32];
    ll idx;
    bool isLazy;
    Node(){
        for(ll i=0;i<32;i++){
            vals[i]=0;
        }
        idx=0;
        isLazy=false;
    }
};


ll n;
vector<ll> v;
vector<struct Node> t;

void fill(struct Node &n,ll val){
    for(ll i=0;i<32;i++){
        n.vals[i] = val;
        val = sqrt(val);
    }
}

struct Node merge(struct Node &n1,struct Node &n2){
    if(n1.isLazy || n2.isLazy){
        // cerr<<"lazy node not merged\n";
        return Node();
    }
    struct Node tmp;
    for(ll i=0;i<32;i++){
        tmp.vals[i] = n1.vals[min(63LL,i+n1.idx)]+n2.vals[min(63LL,i+n2.idx)];
    }
    return tmp;
}

void push(ll id, ll l, ll r){
    if(t[id].isLazy){
        t[id].idx=min(63LL,t[id].idx+1);
        t[id].isLazy=false;
        if(l==r){
            return;
        }
        t[2*id].isLazy=true;
        t[2*id+1].isLazy=true;
    }
}

void build(ll id, ll l, ll r){
    // cerr<<id<<" "<<l<<" "<<r<<"\n";
    if(l==r){
        fill(t[id],v[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}

void update(ll id, ll l, ll r, ll ql, ll qr){
    push(id,l,r);
    if(qr<l || ql>r){
        return;
    }
    if(ql<=l && r<=qr){
        t[id].isLazy=true;
        push(id,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update(id*2,l,mid,ql,qr);
    update(2*id+1,mid+1,r,ql,qr);
    t[id]=merge(t[2*id],t[2*id+1]);
}

struct Node query(ll id, ll l, ll r, ll ql, ll qr){
    push(id,l,r);
    if(qr<l || ql>r){
        return Node();
    }
    if(ql<=l && r<=qr){
        return t[id];
    }
    ll mid=(l+r)/2;
    struct Node n1 = query(2*id,l,mid,ql,qr);
    struct Node n2 = query(2*id+1,mid+1,r,ql,qr);
    return merge(n1,n2);
}

// void debug(){
//     for(int i=0;i<2*n;i++){
//         cerr<<t[i].vals[t[i].idx]<<" ";
//     }
//     cerr<<endl;
// }

int main(){
    fastio
    ll _=0;
    int test=1;
    while(scanf("%lld",&_)!=EOF){
        n=_;
        printf("Case #%d:\n",test);
        v.clear();
        t.clear();
        v.resize(n+1,0);
        t.resize(4*n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&(v[i]));
        }
        build(1,1,n);
        // debug();
        ll q;
        scanf("%lld",&q);
        while(q--){
            ll ch,ql,qr;
            scanf("%lld %lld %lld",&ch, &ql, &qr);
            if(ql>qr){
                swap(ql,qr);
            }
            if(ch==0){
                update(1,1,n,ql,qr);
                // debug();
            }
            else{
                struct Node n1 = query(1,1,n,ql,qr);
                printf("%lld\n",n1.vals[n1.idx]);
            }
        }
        test++;
        printf("\n");
    }
}
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Node{
    ll val;
    ll maxv;
    Node(){
        val=0;
        maxv=0;
    }
};

ll n;
vector<ll> v;
vector<struct Node> t;

struct Node merge(struct Node &n1, struct Node &n2){
    struct Node tmp;
    tmp.val = n1.val+n2.val;
    tmp.maxv = max(n1.maxv,n2.maxv);
    return tmp;
}

void build(ll id,ll l,ll r){
    if(l==r){
        t[id].val=max(v[l],-v[l]);
        t[id].maxv=t[id].val;
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}

void update(ll id,ll l,ll r,ll ql,ll qr){
    if(qr<l || ql>r)return;
    if(t[id].maxv==1)return;
    if(ql<=l && r<=qr && l==r){
        t[id].val=sqrt(t[id].val);
        t[id].maxv=t[id].val;
        return;
    }
    ll mid=(l+r)/2;
    update(2*id,l,mid,ql,qr);
    update(2*id+1,mid+1,r,ql,qr);
    t[id]=merge(t[2*id],t[2*id+1]);
}

struct Node query(ll id, ll l,ll r,ll ql,ll qr){
    if(qr<l || ql>r)return Node();
    if(ql<=l && r<=qr)return t[id];
    ll mid=(l+r)/2;
    struct Node n1=query(2*id,l,mid,ql,qr);
    struct Node n2=query(2*id+1,mid+1,r,ql,qr);
    return merge(n1,n2);
}

void debug(){
    for(int i=0;i<2*n;i++){
        cerr<<t[i].val<<" ";
    }
    cerr<<endl;
    for(int i=0;i<2*n;i++){
        cerr<<t[i].maxv<<" ";
    }
    cerr<<"\n\n-----------------------------\n";
}

int main(){
    fastio
    ll test=0;
    while(scanf("%lld",&n)!=EOF){
        test++;
        cout<<"Case #"<<test<<":\n";
        v.clear();
        t.clear();
        v.resize(n);
        t.resize(4*n);
        for(int i=0;i<n;i++)scanf("%lld",&(v[i]));
        build(1,0,n-1);
        // debug();
        ll q;scanf("%lld",&q);
        while(q--){
            ll ch,ql,qr;scanf("%lld %lld %lld",&ch, &ql, &qr);if(ql>qr)swap(ql,qr);
            if(ch==0){
                update(1,0,n-1,ql-1,qr-1);
                // debug();
            }
            else{
                cout<<query(1,0,n-1,ql-1,qr-1).val<<endl;
            }
        }
        cout<<"\n";
    }
}