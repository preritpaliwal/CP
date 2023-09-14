#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
vector<vector<ll>> a;
vector<ll> hap;
vector<ll> dp;

ll solve(int mask){
    if(dp[mask]!=-1)return dp[mask];
    int submask=(mask&(mask-1));
    ll ans=hap[mask];
    for(int tmp=submask;tmp>0;tmp=(tmp-1)&submask){
        ans=max(ans,hap[tmp^mask]+solve(tmp));
    }
    return dp[mask]=ans;
}

int main(){
    cin>>n;a.resize(n,vector<ll> (n,0)),hap.resize((1<<n),0), dp.resize((1<<n),-1);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){cin>>a[i][j];hap[(1<<i)|(1<<j)]=a[i][j];}
    for(int mask=1;mask<(1<<n);mask++){
        if(hap[mask]!=0)continue;
        int submask=(mask&(mask-1));
        int bit=(submask^mask);
        hap[mask]+=hap[submask];
        // cerr<<hap[mask]<<" "<<mask<<" "<<submask<<" "<<bit<<endl;
        for(int i=0;i<n;i++){
            if(submask&(1<<i)){
                hap[mask]+=hap[bit|(1<<i)];
            }
        }
        // cerr<<hap[mask]<<endl;
    }
    cout<<solve((1<<n)-1);
}