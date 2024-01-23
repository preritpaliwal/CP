#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;string s;cin>>s;ll cnt1=0,cnt0=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    if(cnt1!=cnt0){
        cout<<"-1\n";
        return;
    }
    ll i=0,j=n-1;
    ll nops=0;
    vector<ll> ans;
    while(nops<301){
        while(i<j && s[i]!=s[j]){
            i++;
            j--;
        }
        if(i>=j){
            break;
        }
        if(s[i]=='0'){
            ans.push_back(j+1);
            s=s.substr(0,j+1)+"01"+s.substr(j+1);
        }
        else{
            ans.push_back(i);
            s=s.substr(0,i)+"01"+s.substr(i);
        }
        nops++;
        i++;j++;
    }
    if(nops==301){
        cout<<"-1\n";return;
    }
    cout<<nops<<"\n";
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
        // cerr<<"\n\n";
    }
    return 0;
}