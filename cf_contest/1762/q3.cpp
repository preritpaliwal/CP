#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int pow2(int k){
    long long ans = 1;
    long long cur = 2;
    while(k!=0){
        if(k%2==1){
            ans*=cur;
            if(ans>mod){
                ans = ((ans%mod) +  mod)%mod;
            }
        }
        cur*=cur;
        if(cur>mod){
            cur = (cur%mod + mod)%mod;
        }
        k/=2;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(n,0);
        int dif = 0;
        int free = 0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(i==0){
                v[i] = 1;
                if(s[i]=='0'){
                    dif--;
                }
                else{
                    dif++;
                }
            }
            else{
                if(s[i]=='0'){
                    if(dif<0){
                        dif--;
                        free++;
                        v[i] = pow2(free);
                    }
                    else{
                        dif--;
                        free++;
                        free = free - 1 - dif;
                        dif = -1;
                        // cout<<free<<endl;
                        v[i] = pow2(free);
                    }
                }
                else{
                    if(dif>0){
                        dif++;
                        free++;
                        v[i] = pow2(free);
                    }
                    else{
                        dif++;
                        free++;
                        free = free + dif - 1;
                        dif = 1;
                        v[i] = pow2(free);
                    }
                }
            }
            ans += 1LL*v[i];
            // cout<<v[i]<<endl;
            // cout<<"free,dif = "<<free<<","<<dif<<","<<v[i]<<endl;
            if(ans>mod){
                ans = ((ans%mod) +  mod)%mod;
            }
        }
        cout<<ans<<endl;
    }
}