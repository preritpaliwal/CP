#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,p,q;cin>>n>>p>>q;
    int ans=p;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ans=min(ans,q+a);
    }
    cout<<ans<<endl;
}