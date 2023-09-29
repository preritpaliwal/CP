#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n,k;cin>>n>>k;vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){cin>>v[i].first;v[i].second=i;}
    sort(v.begin(),v.end());int mini=v[n-1].second,maxi=v[n-1].second;
    vector<int> ans(k+1,0);int cur=v[n-1].first;
    for(int i=n-2;i>=0;i--){
        if(v[i].first!=cur)ans[cur]=2*(maxi-mini+1);
        cur=v[i].first;mini=min(mini,v[i].second);maxi=max(maxi,v[i].second);
    }
    ans[cur]=2*(maxi-mini+1);
    for(int i=1;i<=k;i++)cout<<ans[i]<<" ";cout<<endl;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}