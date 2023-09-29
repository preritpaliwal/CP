#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int a;cin>>a;s.insert(a);
    }
    vector<pair<int,int>> d(m);
    for(int i=0;i<m;i++){
        cin>>d[i].second;
    }
    for(int i=0;i<m;i++){
        cin>>d[i].first;
    }
    sort(d.begin(),d.end());
    ll ans=0;
    for(int i=m-1;i>=0;i--){
        auto it=s.lower_bound(d[i].second);
        if(it==s.end())continue;
        ans+=(*it-d[i].first);
        s.erase(it);
    }
    for(auto &it:s){
        ans+=it;
    }
    cout<<ans<<endl;
}