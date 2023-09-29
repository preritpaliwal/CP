#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool comp(const vector<ll> &v1,const vector<ll> &v2){
    if(v1[0]==v2[0]){
        if(v1[1]==v2[1]){
            return v1[2]>v2[2];
        }
        return v1[1]>v2[1];
    }
    return v1[0]<v2[0];
}
const ll maxlen=(ll)8e5+10;
ll t[maxlen];

void insert(ll nn,ll l,ll r,ll idx,ll val){
    if(idx<l || idx>r)return;
    if(l==r){t[nn]=min(t[nn],val);return;}
    ll mid=(l+r)>>1;
    insert(nn<<1,l,mid,idx,val);insert(nn<<1|1,mid+1,r,idx,val);
    t[nn]=min(t[nn<<1],t[nn<<1|1]);
}

ll query(ll nn,ll l,ll r,ll ql,ll qr){
    if(qr<l||ql>r)return 2e9;
    if(ql<=l && r<=qr)return t[nn];
    ll mid=(l+r)>>1;
    return min(query(nn<<1,l,mid,ql,qr),query(nn<<1|1,mid+1,r,ql,qr));
}

int main(){
    for(ll i=0;i<maxlen;i++)t[i]=2e9;
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll> (3,0));
    for(ll i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        sort(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end(),comp);
    map<ll,ll> mp;ll cnt=0;
    for(ll i=0;i<n;i++)mp[v[i][1]]++;
    for(auto &it:mp)it.second=cnt++;
    bool pos=false;
    for(int i=0;i<n;i++){
        if(v[i][2]>query(1,0,n-1,0,mp[v[i][1]]-1)){
            pos=true;break;
        }
        insert(1,0,n-1,mp[v[i][1]],v[i][2]);
    }
    if(pos)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}