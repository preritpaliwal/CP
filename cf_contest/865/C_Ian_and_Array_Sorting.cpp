#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    for(long long i = 0;i<n;i++){
        cin>>v[i];
    }

    for(long long i = 1;i<n-1;i++){
        long long dif = v[i] - v[i-1];
        v[i] -= dif;
        v[i+1] -= dif;
    }

    if(v[n-1]<v[n-2]){
        if(n%2==0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    
    return;

}

int main(){
    long long t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}