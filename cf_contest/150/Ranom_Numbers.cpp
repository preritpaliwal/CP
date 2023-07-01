#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<char,ll> mp;

ll eval(string s){
    ll n = s.size();
    vector<ll> sign(n,0);
    sign[n-1] = 1;
    char largest = s[n-1];
    for(ll i=n-2;i>=0;i--){
        // cerr<<"i= "<<i<<endl;
        if(s[i]<largest){
            sign[i] = -1;
        }
        else{
            sign[i] = 1;
            largest = s[i];
        }
    }
    // cerr<<"here"<<endl;
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ans += mp[s[i]]*sign[i];
    }
    // cerr<<s<<": "<<ans<<endl;
    return ans;
}

void solve(){
    ll tens = 1;
    for(ll i=0;i<5;i++){
        mp['A'+i] = tens;
        tens *=10; 
    }
    string s;
    cin>>s;
    ll n = s.size();

    map<char,ll> idx;
    for(ll i = 0;i<5;i++){
        idx['A'+i] = -1;
    }

    for(ll i = 0;i<n;i++){
        if(idx[s[i]]==-1){
            idx[s[i]] = i;
        }
    }

    ll ans = eval(s);
    for(auto it:idx){
        if(it.second==-1){
            continue;
        }
        for(char j = it.first+1;j<='E';j++){
            string tmp = s;
            // cerr<<"works?";
            tmp[it.second] = j;
            // cerr<<"still works?";
            ans = max(ans, eval(tmp));
        }
    }

    map<char,ll> idx2;
    for(ll i = 0;i<5;i++){
        idx['A'+i] = -1;
    }

    for(ll i = 0;i<n;i++){
        idx2[s[i]] = i;
    }

    for(auto it:idx2){
        if(it.second==-1){
            continue;
        }
        for(char j = it.first-1;j>='A';j--){
            string tmp = s;
            // cerr<<"works?";
            tmp[it.second] = j;
            // cerr<<"still works?";
            ans = max(ans, eval(tmp));
        }
    }

    cout<<ans<<endl;


    // vector<map<char,ll>> pre(n);
    // vector<map<char,ll>> post(n);
    // pre[0][s[0]]++;
    // for(ll i = 1;i<n;i++){
    //     pre[i] = pre[i-1];
    //     pre[i][s[i]]++;

    //     post[n-1-i] = post[n-i];
    //     post[n-1-i][s[n-i]]++;
    // }

    // ll curscore = 0,incr = 0;
    // for(ll i = 0;i<n;i++){
    //     ll sign = 1;
    //     incr = 10000;
    //     for(char j = s[i]+1;j<='E';j++){
    //         if(post[i][j]>0){
    //             sign = -1;
    //         }
    //         if(j!='E'){
    //             incr -
    //         }
    //     }
    //     curscore += sign*mp[s[i]];
    //     incr -= sign*mp[s[i]];



    // }
    return;
}

int main(){
    int t=1;
    cin>>t;
    // cerr<<t<<endl<<endl;
    while(t--){
        solve();
    }
    // cerr<<endl<<endl;
    return 0;
}