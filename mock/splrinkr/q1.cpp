#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);bool valid=true;
    for(int i=0;i<n;i++){cin>>a[i];if(i!=0)valid&=(!(a[i-1]==1 &&a[i]==1));}
    if(!valid){
        cout<<"NO\n"<<endl;
        return ;
    }
    if(n==1){
        if(a[0]==1)cout<<"NO\n";
        else cout<<((k<=1)?"YES\n":"NO\n");
        return;
    }
    ll maxi=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            bool pos=true;
            if(i!=0)if(a[i-1]==1)pos=false;
            if(i!=n-1)if(a[i+1]==1)pos=false;
            if(pos){maxi++;a[i]=1;}
        }
    }
    cout<<(maxi>=k ? "YES":"NO")<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}