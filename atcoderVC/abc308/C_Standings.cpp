#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool comp(const pair<long double,int> &p1,const pair<long double,int> & p2){
    if(p1.first==p2.first){
        // cerr<<p1.second<<" "<<p2.second<<endl;

        return p1.second>p2.second;
    }
    return p1.first<p2.first;
}
int main(){
    int n;cin>>n;vector<pair<long double,int>> v;for(int i=1;i<=n;i++){
        long double a,b;cin>>a>>b;
        v.push_back({a/(a+b),i});
    }
    sort(v.begin(),v.end(),comp);
    for(int i=n-1;i>=0;i--){
        cout<<v[i].second<<" ";
    }
}