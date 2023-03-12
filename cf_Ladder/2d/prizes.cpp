#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> p(n);
    for(auto &v:p){
        cin>>v;
    }
    vector<pair<long long,long long>> v(5);
    for(long long i = 0;i<5;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    vector<long long> ans(5,0);
    sort(v.begin(),v.end());
    long long cur = 0;
    // cout<<"starts"<<endl;
    for(long long i = 0;i<n;i++){
        cur += p[i];
        for(int j = 4;j>=0;j--){
            if(v[j].first<=cur){
                int tmp = cur/v[j].first;
                cur -= tmp*v[j].first;
                ans[v[j].second] += tmp;
            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n"<<cur;
    return 0;
}