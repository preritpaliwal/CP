/* 
This approach gave TLE ofcourse..!!

#include <bits/stdc++.h>
using namespace std;



long long recur(vector<long long> &l,vector<long long> &r, long long k, long long n){
    if(n==l.size()){
        return (long long)1e18;
    }
    int curlen = r[n]-l[n]+1;
    long long pointerLock = 0;
    if(n!=0){
        pointerLock = r[n-1];
    }
    if(curlen>=k){
        return min(l[n]-pointerLock+k-1  +2,r[n] - pointerLock + recur(l,r,k,n+1));
    }
    else{
        return min(r[n]-pointerLock + 2 + recur(l,r,k - (r[n]-l[n]+1),n+1),r[n]-pointerLock +recur(l,r,k,n+1));
    }
}

void solve(){
    long long n,k;
    cin>>n>>k;
    vector<long long> l(n),r(n);
    for(long long i = 0;i<n;i++){
        cin>>l[i];
    }
    long long full = 0;
    for(long long i = 0;i<n;i++){
        cin>>r[i];
        full += r[i]-l[i]+1;
    }
    if(k>full){
        cout<<-1<<endl;;
        return;
    }

    // cout<<recur(l,r,k,0)<<endl;

    vector<long long> kmax(n);
    vector<long long> cost(n);
    for(int i = 0;i<n;i++){
        
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

ll n,k;
vector<pair<ll,ll>> v;

void solve(){
    v.clear();
    cin>>n>>k;
    v.resize(n+1);
    for(ll i=1;i<=n;i++)cin>>v[i].first;
    for(ll i=1;i<=n;i++)cin>>v[i].second;
    ll longLen=0,shortLen=0;
    ll ans=LLONG_MAX;
    for(ll i=1;i<=n;i++){
        if(v[i].first==v[i].second)shortLen++;
        else longLen+=(v[i].second-v[i].first+1);
        if(longLen>=k){
            // v[i].first-1+(k-(longLen-(v[i].second-v[i].first+1)))
            ans=min(ans,2*(i-shortLen)+v[i].second-(longLen-k));
            break;
        }
        else{
            if(longLen+shortLen>=k){
                ans=min(ans,(k-longLen + i-shortLen)*2 + v[i].second);
            }
        }
    }
    cout<<((ans==LLONG_MAX)?-1:ans)<<endl;
}

int main(){
    fastio
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}