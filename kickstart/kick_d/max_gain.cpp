#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll> &a,ll k){
    if(k==0){
        return 0;
    }
    ll ans = a[k-1];
    ll n = (ll)a.size();
    for(ll i = 1;i<k;i++){
        ans = max(ans,a[k-i-1]+a[n-1]-a[n-i-1]);
    }
    ans = max(ans,a[n-1]-a[n-k-1]);
    return ans;
}

int main(){
    ll t;
    cin>>t;
    for(ll _ = 0;_<t;_++){
        cout<<"Case #"<<_+1<<": ";
        ll n,m,k;
        cin>>n;
        vector<ll> a(n);
        for(auto &i:a){
            cin>>i;
        }
        cin>>m;
        vector<ll> b(m);
        for(auto &i:b){
            cin>>i;
        }
        cin>>k;
        for(ll i = 1;i<n;i++){
            a[i] = a[i] + a[i-1];
        }
        for(ll i = 1;i<m;i++){
            b[i] = b[i] + b[i-1];
        }
        ll ans = 0;
        for(ll q = 0;q<=k;q++){
            if(q>min(n,m) || k-q>min(n,m)){
                continue;
            }
            ans = max(ans,solve(a,q)+solve(b,k-q));
        }
        cout<<ans<<endl;
    }
}