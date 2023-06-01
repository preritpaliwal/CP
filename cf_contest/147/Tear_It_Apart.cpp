#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n  =s.size();
    map<char,vector<int>> mp;
    for(int i  = 0;i<s.size();i++){
        mp[s[i]].push_back(i);
    }
    int ans = 1e9;
    for(auto p:mp){
        vector<int> v = p.second;
        int curans = 0;
        int block = v[0];
        while(block!=0){
            block/=2;
            curans++;
        }
        for(int i = 0;i<v.size();i++){
            if(i==v.size()-1){
                int ops = 0;
                block = n-v[i]-1;
                while(block!=0){
                    block/=2;
                    ops++;
                }
                curans = max(curans,ops);
                continue;
            }
            int ops = 0;
            block = v[i+1]-v[i]-1;
            while(block!=0){
                block/=2;
                ops++;
            }
            curans = max(curans,ops);
        }
        // cout<<ans<<" "<<curans<<endl;
        ans = min(ans,curans);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
1 1 1 1
1 3 5

*/