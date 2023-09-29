#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;int f;cin>>f;
    int ans=0;
    for(int i=1;i<n;i++){
        int a;cin>>a;
        ans=max(ans,a-f+1);
    }
    cout<<ans<<endl;
}