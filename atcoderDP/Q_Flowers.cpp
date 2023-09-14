#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> t;
void update(int idx,int l,int r,int pos,ll val){
    if(pos>r || pos<l)return;
    if(l==r){t[idx]=val;return;}
    int mid=(0ll+l+r)/2;
    update(idx*2,l,mid,pos,val);update(idx*2+1,mid+1,r,pos,val);
    t[idx]=max(t[2*idx],t[2*idx+1]);
}
ll query(int idx,int l,int r,int ql,int qr){
    if(ql>r || qr<l)return -1e9;
    if(ql<=l && r<=qr)return t[idx];
    int mid=(0ll+l+r)/2;
    return max(query(2*idx,l,mid,ql,qr),query(2*idx+1,mid+1,r,ql,qr));
}
int main(){
    int n;cin>>n;
    vector<ll> h(n),a(n);
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>a[i];
    t.resize(4*(n+2),0);
    for(int i=0;i<n;i++){
        ll best=query(1,0,n,0,h[i]-1);
        update(1,0,n,h[i],a[i]+best);
    }
    cout<<query(1,0,n,0,n)<<endl;
}