#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        m--;
        vector<ll> v(n);
        for(auto &i:v){
            cin>>i;
        }

        ll ans = 0;
        ll cur = 0;
        multiset<ll> s; 
        for(int i = m;i>0;i--){
            cur +=v[i];
            s.insert(-v[i]);
            // cout<<cur<<endl;
            if(cur>0){
                int val = *(s.begin());
                s.erase(s.begin());
                cur += 2*val;
                ans++;
            }
        }

        cur = 0;
        s.clear(); 
        for(int i = m+1;i<n;i++){
            cur +=v[i];
            // cout<<cur<<endl;
            s.insert(v[i]);
            if(cur<0){
                int val = *(s.begin());
                s.erase(s.begin());
                cur -= 2*val;
                ans++;
            }
        }

        cout<<ans<<endl;

        

    }
    return 0;
}