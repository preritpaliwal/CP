#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i].first;
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> ans;
        for(int i = 1;i<n;i++){
            int tmp = v[i].first%v[i-1].first;
            if(tmp==0){
                continue;
            }
            ans.push_back({v[i].second+1,v[i-1].first-tmp});
            v[i].first += v[i-1].first-tmp;
        }
        cout<<ans.size()<<endl;
        for(auto p:ans){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}