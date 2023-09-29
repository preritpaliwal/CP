#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll> (m));
    ordered_set o;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++)o.insert(v[i][j]);
        if(i==n-1)continue;
        for(int j=0;j<m;j++){
            ll cnt= o.order_of_key(v[i][j]);
            ans+=((j+1)*(n-2-i)+cnt+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}