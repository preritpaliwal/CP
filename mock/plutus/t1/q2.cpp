#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;vector<ll> a(n);
    vector<vector<ll>> arr(n,vector<ll> (101,0));
    for(int i=0;i<n;i++){
        cin>>a[i];
        arr[i][a[i]]+=1;
        if(i!=0){
            for(int j=0;j<=100;j++){
                arr[i][j]+=arr[i-1][j];
            }
        }
    }
    ll q;cin>>q;
    while(q--){
        // cerr<<"hrer\n";
        ll l,r;cin>>l>>r;
        l--;
        ll dif=r-l;
        ll tot=dif/n;
        l=(l+n)%n;r%=n;
        // cerr<<l<<" "<<r<<"\n";
        vector<ll> diff(101,0);
        if(l<=r){
            for(int i=0;i<=100;i++){
                diff[i]=arr[r][i]-arr[l][i] + tot*arr[n-1][i];
            }
        }
        else{
            for(int i=0;i<=100;i++){
                diff[i]=arr[r][i]-arr[l][i] + (tot+1)*arr[n-1][i];
            }
        }
        int val=0;
        for(int i=1;i<=100;i++){
            if(diff[i]>=diff[val]){val=i;}
        }
        cout<<val<<"\n";
    }
}