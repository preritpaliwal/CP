#include <bits/stdc++.h>

using namespace std;


void solve(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    vector<long long> l(n),r(n);
    for(long long i = 0;i<n;i++){
        cin>>v[i];
        l[i] = v[i]+i;
        r[i] = v[i]-i;
    }
    for(int i = 1;i<n;i++){
        l[i] = max(l[i],l[i-1]);
        r[n-i-1] = max(r[n-i-1],r[n-i]);
    }
    long long ans = -1;
    for(int i = 1;i<n-1;i++){
        ans = max(ans, l[i-1] + r[i+1] + v[i]);
    }
    cout<<ans<<endl;
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