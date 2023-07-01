#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a,b;
    ll _;
    for(ll i = 0;i<n;i++){
        cin>>_;
        if(_<0){
            b.push_back(_);
        }
        else{
            a.push_back(_);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll bs = b.size();
    ll as = a.size();
    if(bs==0){
        cout<<"No\n";
        return;
    }
    vector<ll> ans(n);
    ll ai = as-1;
    ll bi = bs-1;
    ll curSum = 0;
    ll diff = a[as-1] - b[0];
    ll i;
    cout<<"Yes\n";
    for(i = 0;i<n;i++){
        if(ai<0){
            ans[i] = b[bi--];
        }
        else if(bi<0){
            ans[i] = a[ai--];
        }
        else{
            if(curSum+a[ai]<diff){
                ans[i] = a[ai];
                curSum += a[ai--];
            }
            else{
                curSum += b[bi];
                ans[i] = b[bi--];
            }
        }
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}