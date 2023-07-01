#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    string s;
    vector<vector<ll>> v(26, vector<ll> (n,0));
    for(ll i = 0;i<n;i++){
        cin>>s;
        for(ll j = 0;j<s.size();j++){
            v[s[j]-'a'][i] = 1 - v[s[j]-'a'][i];
        }
    }
    for(int i = 0;i<26;i++){
        for(int j = 0;j<n;j++){
            cerr<<v[i][j];
        }
        cerr<<endl;
    }
    ll ans = 0;
    for(ll i = 0;i<26;i++){
        vector<ll> mask = v[i];
        for(int j = 0;j<26;j++){
            if(i==j){
                continue;
            }
            for(int k = 0;k<n;k++){
                if(mask[k]==0 && v[j][k]==0){
                    mask[k] = 1;
                }
            }
        }
        ll ones = 0;
        for(int k = 0;k<n;k++){
            if(mask[k]==1){
                ones++;
            }
            cout<<mask[k];
        }
        cout<<"\ni,ones: "<<i<<" "<<ones<<endl;
        ans+= 1LL*(ones)*(n-ones);
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}