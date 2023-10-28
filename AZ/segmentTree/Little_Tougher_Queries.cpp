#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    vector<int> v;
};

vector<Node> t;
int n;
vector<int> a;
Node merge(const Node &n1,const Node &n2){
    Node n;
    n.v.assign(n1.v.size()+n2.v.size(),0);
    int i=0,j=0,k=0;
    while(i<n1.v.size() && j<n2.v.size()){
        if(n1.v[i]<n2.v[j]){
            n.v[k++]=n1.v[i++];
        }
        else{
            n.v[k++]=n2.v[j++];
        }
    }
    while(i<n1.v.size()){
        n.v[k++]=n1.v[i++];
    }
    while(j<n2.v.size()){
        n.v[k++]=n2.v[j++];
    }
    return n;
}

void build(int nn,int l,int r){
    if(l==r){
        t[nn].v.push_back(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(nn<<1,l,mid);build(nn<<1|1,mid+1,r);
    t[nn] = merge(t[nn<<1],t[nn<<1|1]);
}

int query(int nn,int l,int r,int ql,int qr,int ai){
    if(qr<l || r<ql) return 0;
    if(ql<=l && r<=qr) {
        int tmp2= lower_bound(t[nn].v.begin(),t[nn].v.end(),ai)-t[nn].v.begin();        
    return tmp2;
        }
    int mid=(l+r)>>1;
    int tmp=query(nn<<1,l,mid,ql,qr,ai)+query(nn<<1|1,mid+1,r,ql,qr,ai);
    return tmp;
}

bool check(int ai,int ql,int qr,int idx){
    return query(1,0,n-1,ql,qr,ai)<=idx;
}

int main(){
    int q;cin>>n>>q;
    t.resize(4*(n+1));
    a.resize(n);for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        int bl=0,br=1e9+1,ans=0;;
        while(bl<=br){
            int mid=(bl+br)>>1;
            if(check(mid,l-1,r-1,k-1)){
                ans=mid;
                bl=mid+1;
            }
            else{
                br=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}