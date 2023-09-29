#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,d;cin>>n>>d;
    vector<string> v(n);for(int i=0;i<n;i++)cin>>v[i];
    // string ans;
    ll ans=0;
    ll f=0;
    for(int i=0;i<d;i++){
        int cur=1;
        for(int j=0;j<n;j++){
            if(v[j][i]=='x')cur=0;
        }
        if(cur==1){
            ans++;
        }
        else{
            f=max(f,ans);
            ans=0;
        }
    }
    cout<<max(f,ans)<<endl;
    return 0;
}