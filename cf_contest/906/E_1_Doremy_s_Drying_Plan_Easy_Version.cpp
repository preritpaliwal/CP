#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vector<pair< ll,set<ll>>> city(n+2);
    vector<pair<ll,ll>> r(m);
    for(ll i=0;i<m;i++){
        cin>>r[i].first>>r[i].second;
        city[r[i].first].first++;
        city[r[i].first].second.insert(i);
        city[r[i].second+1].first--;
        city[r[i].second+1].second.insert(i);
    }
    set<ll> s;
    vector<map<ll,ll>> adj(m);
    vector<ll> cnt(m,0);
    ll ans=0;
    for(ll i=1;i<n+1;i++){
        if(i!=0){
            city[i].first+=city[i-1].first;
            for(ll c:city[i].second){
                if(s.find(c)==s.end()){
                    s.insert(c);
                }
                else{
                    s.erase(c);
                }
            }
        }
        else{
            for(ll j:city[i].second){
                s.insert(j);
            }
        }

        if(city[i].first==1){
            cnt[*(s.begin())]++;
        }
        else if(city[i].first==2){
            auto it=s.begin();
            auto it2=it++;
            adj[*it][*it2]++;
            adj[*it2][*it]++;
        }
        else if(city[i].first==0){
            ans++;
        }
    }
    ll ni=0;
    ll free=cnt[ni];
    ll maxr=cnt[ni];
    for(ll i=1;i<m;i++){
        ll curmax=maxr+cnt[i];
        for(auto &p:adj[i]){
            if(p.first<i){
                curmax=max(curmax,p.second+cnt[p.first]+cnt[i]);
            }
        }
        maxr=max(cnt[i],maxr);
        free=max(free,curmax);
    }
    cout<<ans+free<<"\n";
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}