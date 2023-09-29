#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    vector<pair<int,int>> v{{1,2},{2,3},{4,5},{5,6},{7,8},{8,9}};
    int a,b;cin>>a>>b;
    for(int i=0;i<v.size();i++){
        if(a==v[i].first && b==v[i].second){
            cout<<"Yes\n";return 0;
        }
    }
    cout<<"No\n";
    return 0;
}