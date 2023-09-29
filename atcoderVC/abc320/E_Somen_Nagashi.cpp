#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
    ll n,m;cin>>n>>m;
    vector<ll> ans(n,0);
    priority_queue<pair<ll,ll>> busy;
    set<ll> av;
    for(int i=0;i<n;i++)av.insert(i);
    for(int i=0;i<m;i++){
        ll ti,wi,si;cin>>ti>>wi>>si;
        while(!busy.empty()){
            if((-1*(busy.top().first))>ti)break;
            av.insert(busy.top().second);
            busy.pop();
        }
        if(av.empty())continue;
        ll fr=*(av.begin());
        av.erase(fr);
        ans[fr]+=wi;
        busy.push({-ti-si,fr});
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<endl;
    return  0;
    
}