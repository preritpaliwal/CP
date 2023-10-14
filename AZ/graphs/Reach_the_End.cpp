#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,x,r1,r2;
    cin>>n>>x>>r1>>r2;
    vector<ll> pr(n+1,1);
    pr[0]=pr[1]=0;
    ll cnt=0;
    for(ll i=1;i<pr.size();i++){
        if(pr[i]==1){
            cnt++;
            for(ll j=i*i;j<pr.size();j+=i){
                pr[j]=0;
            }
        }
        pr[i]=cnt;
    }
    queue<pair<ll,ll>> q;
    q.push({0,1});
    while(!q.empty()){
        auto cur=q.front();q.pop();
        if(pr[cur.second]*r2>=r1*cur.second && cur.second+x<=n){
            if(cur.second+x<n ){
                q.push({cur.first+1,cur.second+x});
            }
            else{
                cout<<cur.first+1<<"\n";
                break;
            }
        }
        else{
            if(cur.second+1==n){
                cout<<cur.first+1<<"\n";
                break;
            }
            else{
                q.push({cur.first+1,cur.second+1});
            }
        }
    }
}