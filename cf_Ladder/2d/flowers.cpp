#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;

int main(){
    int t,k;
    cin>>t>>k;
    vector<long long> v(1e5+2,0);
    vector<long long> vp(1e5+2,0);
    for(int i = 0;i<1e5+2;i++){
        if(i<k){
            v[i] = 1;
        }
        else{
            v[i] = ((v[i-1]+v[i-k])%mod + mod)%mod;
        }
        if(i==0){
            vp[i] = 0;
        }
        else{
            vp[i] = ((v[i] + vp[i-1])%mod + mod)%mod;
        }
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<((vp[b]-vp[a-1])%mod + mod)%mod<<endl;
    }
    return 0;
}