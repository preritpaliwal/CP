#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    string s;cin>>s;
    int mask=0;
    map<int,int> mp;
    mp[mask]=1;
    ll ans=0;
    for(char c:s){
        mask^=(1<<(c-'a'));
        if(mp.find(mask)!=mp.end()){
            ans+= mp[mask];
        }
        for(int i=0;i<26;i++){
            if(mp.find(mask^(1<<i))!=mp.end()){
                ans+=mp[mask^(1<<i)];
            }
        }
        mp[mask]++;
        // cerr<<ans<<endl;
    }
    cout<<ans<<endl;
    // cerr<<"---------\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}