#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
ll sp[(int)1e6+1],sr[(int)1e6+1],sc[(int)1e6+1],ns[(int)1e6+1];
int main(){
    ll h,w,k;cin>>h>>w>>k;
    ll x1,x2,x3,x4;cin>>x1>>x2>>x3>>x4;
    sp[0]=1,sr[0]=0,sc[0]=0,ns[0]=0;
    for(int i=1;i<=k;i++){
        sp[i]=((h-1)*sc[i-1]%mod+(w-1)*sr[i-1]%mod)%mod;
        sr[i]=(sp[i-1]+(w-2)*sr[i-1]%mod+(h-1)*ns[i-1]%mod)%mod;
        sc[i]=(sp[i-1]+(h-2)*sc[i-1]%mod+(w-1)*ns[i-1]%mod)%mod;
        ns[i]=(sr[i-1]+sc[i-1]+(h+w-4)*ns[i-1]%mod)%mod;
    }
    if(x1==x3){
        if(x2==x4){
            cout<<sp[k];
        }
        else{
            cout<<sr[k];
        }
    }
    else{
        if(x2==x4){
            cout<<sc[k];
        }
        else{
            cout<<ns[k];
        }
    }
}