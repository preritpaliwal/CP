#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll v[n];
    map<ll,vector<ll>> odd;
    map<ll,vector<ll>> even;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        if(i&1){
            odd[v[i]].push_back(i);
        }
        else{
            even[v[i]].push_back(i);
        }
    }
    ll ans = (k/2)*(n-k+1);
    ll oddUsed  =0;
    for(auto it:odd){
        cerr<<"v[i] = "<<it.first<<"\t";
        ll l = 0,r = 0;
        ll curUsed = 0;
        while(l<it.second.size()){
            while(r<it.second.size() && it.second[l]+k>=it.second[r]){
                r++;
            }
            cerr<<"l,r: "<<l<<","<<r<<endl;
            curUsed += (r-l-1);
            l++;
        }
        cerr<<"curUsed: "<<curUsed<<endl;
        oddUsed += curUsed;
    }

    ll evenUsed = 0;
    for(auto it:even){
        cerr<<"v[i] = "<<it.first<<"\t";
        ll l = 0,r = 0;
        ll curUsed = 0;
        while(l<it.second.size()){
            while(r<it.second.size() && it.second[l]+k>=it.second[r]){
                r++;
            }
            cerr<<"l,r: "<<l<<","<<r<<endl;
            curUsed += (r-l-1);
            l++;
        }
        cerr<<"curUSED: "<<curUsed<<endl;
        evenUsed += curUsed;
    }
    cerr<<ans<<" "<<oddUsed<<" "<<evenUsed<<endl;
    cout<<ans - oddUsed - evenUsed<<endl;

    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}