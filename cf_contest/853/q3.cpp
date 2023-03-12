#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n);
    map<long long,long long> lastEntered;
    map<long long,long long> lastRemoved;
    map<long long,long long> notExist;
    
    for(long long i = 0;i<n;i++){
        cin>>a[i];
        lastEntered[a[i]] = 0;
        notExist[a[i]] = 0;
    }
    for(long long i = 1;i<=m;i++){
        long long p,x;
        cin>>p>>x;
        p--;
        lastRemoved[a[p]] = i;
        lastEntered[x] = i;
        notExist[x] += i-lastRemoved[x];
        a[p] = x;
    }
    for(auto q:lastRemoved){
        if(q.second>lastEntered[q.first]){
            notExist[q.first] += m+1-q.second;
        }
    }
    long long ans = 0;
    for(auto q:notExist){
        // cout<<q.first<<": "<<q.second<<endl;
        ans += (m+1)*m/2 - (q.second-1)*(q.second)/2;
    }
    cout<<ans<<endl;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}