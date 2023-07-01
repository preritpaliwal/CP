#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll prev = 0;
    string s;
    int once = -1;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        if(prev<=v[i] && once ==-1){
            s += '1';
            prev = v[i];
        }
        else{
            if(v[i]<=v[0]){
                if(once==-1){
                    s += '1';
                    once = v[i];
                }
                else{
                    if(once<=v[i]){
                        s += '1';
                        once = v[i]; 
                    }
                    else{
                        s += '0';
                    }
                }
            }
            else{
                s += '0';
            }
        }
    }

    cout<<s<<endl;

    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}