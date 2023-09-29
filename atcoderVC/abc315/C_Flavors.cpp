#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;vector<pair<int,int>> v(n);for(auto &it:v)cin>>it.second>>it.first;
    sort(v.begin(),v.end());
    if(v[n-1].second!=v[n-2].second){
        cout<<v[n-1].first+v[n-2].first<<endl;
    }
    else{
        int a=v[n-2].first/2;
        for(int i=n-3;i>=0;i--){
            if(v[n-1].second!=v[i].second){
                a=max(a,v[i].first);
                break;
            }
        }
        cout<<v[n-1].first+a<<endl;
    }
    return 0;
}