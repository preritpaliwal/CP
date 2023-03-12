#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ = 1e6+1;
vector<bool> seive(_,true);
int mod = 998244353;

bool check(string s,int n){
    for(int i = s.size()-1;i>0;i--){
        if(s[i]=='1'){
            n--;
            if(n==0){
                return true;
            }
        }
        else{
            break;
        }
    }
    return false;
}

void update(string s){
    
}

void solve(){
    ll n;
    cin>>n;
    map<ll,ll> m;
    for(ll i = 0;i<2*n;i++){
        ll a;
        cin>>a;
        m[a]++;
    }
    ll ones = m[1];
    vector<ll> primes;
    vector<ll> non;
    for(auto &x:m){
        if(x.first==1){
            continue;
        }
        if(seive[x.first]){
            primes.push_back(x.second);
        }
        else{
            non.push_back(x.second);
        }
    }

    if(primes.size()<n){
        cout<<"0\n";
    }
    else{
        string s;
        for(ll i = 0;i<primes.size();i++){
            if(i<n){
                s += '1';
            }
            else{
                s += '0';
            }
        }
        ll ans = 0;
        while(check(s,n)){
            ans += calc(primes,non,ones,s);
            update(s);
        }
    }
}

void calcSeive(){
    seive[0] = false;
    seive[1] = false;
    for(ll i = 2;i<_;i++){
        if(seive[i]){
            for(ll j = i*i;j<_;j++){
                seive[j] = false;
            }
        }
    }
}

int main(){
    calcSeive();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}