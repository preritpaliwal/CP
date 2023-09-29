#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];
    vector<ll> st;vector<ll> vis(n+1,0);
    ll cur=1;
    while(vis[cur]==0){
        vis[cur]=1;
        st.push_back(cur);
        cur=a[cur];
    }
    vector<ll> ans{cur};
    while(st.back()!=cur){
        ans.push_back(st.back());
        st.pop_back();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(ll i:ans)cout<<i<<" ";
    return 0;
}