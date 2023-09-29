#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,h,x;cin>>n>>h>>x;
    int ans=-1;
    for(int i=1;i<=n;i++){
        int p;cin>>p;
        if(h+p>=x && ans==-1){ans=i;}
    }
    cout<<ans<<endl;
    return 0;
}