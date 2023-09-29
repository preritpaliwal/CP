#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n;cin>>n;
    vector<vector<int>> v(n);
    vector<set<int>> freq(51);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v[i].resize(a);
        for(int j=0;j<a;j++){
            cin>>v[i][j];
            freq[v[i][j]].insert(i);
        }
    }
    int ans=0;
    for(int i=1;i<=50;i++){
        if(freq[i].empty())continue;
        set<int> s;
        for(int j=0;j<n;j++){
            if(freq[i].find(j)==freq[i].end()){
                for(int k=0;k<v[j].size();k++){
                    s.insert(v[j][k]);
                }
            }
        }
        ans=max(ans,(int)s.size());
        // cerr<<s.size()<<endl;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}