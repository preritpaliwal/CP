#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--){
        int n;cin>>n;
        multiset<int> ms;
        for(int i=0;i<n;i++){
            int cur;cin>>cur;
            if(ms.empty()){
                ms.insert(cur);
                continue;
            }
            else if(ms.upper_bound(cur)!=ms.end()){
                ms.erase(ms.upper_bound(cur));
            }
            ms.insert(cur);
        }
        cout<<ms.size()<<"\n";
    }
}