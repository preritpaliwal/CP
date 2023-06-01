#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    for(long long i = 0;i<n;i++){
        cin>>v[i];
    }
    long long ans = 0;
    long long curX = 1e9+2;
    for(long long i = 0;i<n/2;i++){
        if(v[i]%curX!=v[n-i-1]%curX){
            long long dif = abs(v[i]-v[n-i-1]);
            if(ans==0){
                curX = dif;
            }
            else{
                curX = __gcd(curX,dif);
            }
            ans = curX;
        }
    }
    cout<<ans<<endl;
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