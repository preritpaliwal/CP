#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll q;
    cin>>q;
    ll lh=1,rh = LLONG_MAX;
    for(ll i = 0;i<q;i++){
        ll t;
        cin>>t;
        if(t==1){
            ll a,b,n;
            cin>>a>>b>>n;
            ll newl = (a-b)*(n-1) +  b +1;
            ll newr = (a-b)*(n-1)  + a;
            if(n==1){
                newl = 1;
            }
            bool used = false;
            if(lh<=newr && rh>=newl){
                used = true;
                lh = max(newl,lh);
                rh = min(newr,rh);
            }
            else{
                used = false;
            }
            if(used){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        else{
            ll a,b;
            cin>>a>>b;
            ll k = max(0LL,(lh-a)/(a-b));
            ll cov = k*(a-b);
            // cout<<"cov: "<<cov<<endl;
            if(cov+a>=rh){
                cout<<k+1<<" ";
            }
            if(cov+a>=lh && cov+a<rh){
                cout<<-1<<" ";
            }
            while(cov+a<lh){
                cov += (a-b);
                if(cov+a>=rh){
                    cout<<1+ ++k<<" ";
                }
                if(cov+a>=lh && cov+a<rh){
                    cout<<-1<<" ";
                }
            }
        }
        // cout<<"l,r "<<lh<<" "<<rh<<endl;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}