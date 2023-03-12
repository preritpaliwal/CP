#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define qll queue<ll>
#define qpll queue<pair<ll,ll>>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>> 
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
void print(vll v){
    fo0(i,v.size()){cout<<v[i]<<" ";}
    cout<<endl;}
int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vll v(n);
        ll total = 0;
        int dist = 0;
        vll v1,v2;
        fo(i,0,n){
            cin>>v[i];
            v[i]%=3;
            if(v[i]==1){
                v1.pb(i);
            }
            if(v[i]==2){
                v2.pb(i);
            }
            total += v[i];
        }
        if(total%3!=0){
            cout<<-1<<endl;
            continue;
        }
        ll ans = 0;
        ll s1 = v1.size();
        ll s2 = v2.size();
        ans += min(s1,s2);
        s1 -= ans;
        s2 -= ans;
        ans += 2*s1/3;
        ans += 2*s2/3;
        cout<<ans<<endl;
    }
    return 0;
}