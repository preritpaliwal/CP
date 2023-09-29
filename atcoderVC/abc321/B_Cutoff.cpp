#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n,x;cin>>n>>x;
    int mini=1e9,maxi=-1,sum=0;
    vector<int> v(n-1);for(int &i:v){cin>>i;maxi=max(maxi,i);mini=min(mini,i);sum+=i;}
    int curscore=sum-mini-maxi;
    int ans=0;
    if(x<=curscore+mini){
        ans=0;
    }
    else if(x>curscore+maxi){
        ans=-1;
    }
    else{
        ans=x-curscore;
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
