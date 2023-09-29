#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n,0),b(m,0);
    for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<m;i++)cin>>b[i];
    vector<int> v(32,0);
    for(int i=0;i<m;i++){
        int idx=0;
        while(b[i]!=0){
            v[idx++]|=b[i]&1;
            b[i]>>=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=a[i];
    }
    int mina,maxa;
    if(n%2==1){
        mina=ans;
        for(int i=0;i<32;i++){
            if(!(ans&(1<<i))){
                if(v[i]>0){
                    ans^=(1<<i);
                }
            }
        }
        maxa=ans;
    }
    else{
        maxa=ans;
        for(int i=0;i<32;i++){
            if(ans&(1<<i)){
                if(v[i]>0){
                    ans^=(1<<i);
                }
            }
        }
        mina=ans;
    }
    cout<<mina<<" "<<maxa<<endl;
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}