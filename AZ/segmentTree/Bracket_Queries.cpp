#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int ost{};
    int cst{};
    int len{};
    Node(){}
};

vector<Node> t;
string s;
int n;

Node merge(const Node &n1,const Node &n2){
    Node n;
    n.len=n1.len+n2.len+2*min(n1.ost,n2.cst);
    n.ost=n2.ost+n1.ost-min(n1.ost,n2.cst);
    n.cst=n1.cst+n2.cst-min(n1.ost,n2.cst);
    return n;
}

void build(int nn,int l,int r){
    if(l==r){
        if(s[l]=='('){
            t[nn].ost=1;
            t[nn].cst=0;
            t[nn].len=0;
        }
        else{
            t[nn].ost=0;
            t[nn].cst=1;
            t[nn].len=0;
        }
        return;
    }
    int mid=(l+r)/2;
    build(nn<<1,l,mid);build(nn<<1|1,mid+1,r);
    t[nn] = merge(t[nn<<1],t[nn<<1|1]);
}

Node query(int nn,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return Node();
    if(ql<=l && r<=qr)return t[nn];
    int mid=(l+r)/2;
    return merge(query(nn<<1,l,mid,ql,qr),query(nn<<1|1,mid+1,r,ql,qr));
}

int main(){
	cin>>s;n=s.size();
    t.resize(4*(n+1));
    build(1,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(1,0,n-1,l-1,r-1).len<<"\n";
    }
}