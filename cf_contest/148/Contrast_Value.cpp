#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        if(v[0]==v[1]){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
        return;
    }
    int dir = 0;
    ll ans = 1;
    for(int i=1;i<n;i++){
        // cout<<dir<<" : dir"<<endl;
        // cout<<v[i]<<" "<<v[i-1]<<endl;
        if(dir==0){

            if(v[i]>v[i-1]){
                dir++;
                ans++;
            }
            else if(v[i]<v[i-1]){
                ans++;
                dir--;
            }
        }
        else if(dir==1 && v[i]<v[i-1]){
            ans++;
            dir=-1;
        }
        else if(dir==-1 && v[i]>v[i-1]){
            ans++;
            dir=1;
        }
    }
    cout<<ans<<endl;
}


int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}