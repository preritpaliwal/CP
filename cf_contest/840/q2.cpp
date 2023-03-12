#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<pair<ll,ll>> &v,ll &dead,ll k){
    ll l = dead;
    ll r = v.size()-1;
    ll ans = r+1;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(k>=v[mid].first){
            l = mid+1;
        }
        else{
            ans = mid;
            r = mid-1;
        }
    }
    dead = ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>> v(n);
        for(ll i = 0;i<n;i++){
            cin>>v[i].first;
        }
        for(ll i = 0;i<n;i++){
            cin>>v[i].second;
        }
        sort(v.begin(),v.end());
        vector<ll> premin(n);
        premin[n-1] = v[n-1].second;
        for(ll i = n-2;i>=0;i--){
            premin[i] = min(premin[i+1],v[i].second);
        }
        ll dead = 0;
        ll k_cur = k;
        ll reduced_k = 0;
        bool yes = false;
        while(true){
            // cout<<dead<<" "<<k_cur<<" "<<reduced_k<<endl;
            update(v,dead,k_cur);
            if(dead==n){
                yes = true;
                break;
            }
            reduced_k += premin[dead];
            k_cur += k-reduced_k;
            if(k<=reduced_k){
                break;
            }
        }
        if(yes){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}