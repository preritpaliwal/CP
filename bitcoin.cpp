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
        fo0(i,n){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll sum = accumulate(v.begin(),v.end(),0);
        ll i = 0,j = n-1;
        ll ans = 0;
        while(v[i]<v[j]){
            if(sum*2 == (v[i]+v[j])*n){
                ans++;
                if(v[i+1]-v[i]>v[j]-v[j-1]){
                    j++;
                }
                else{
                    i++;
                }
                
            }
            else if(sum*2>(v[i]+v[j])*n){
                i++;
            }
            else{
                j++;
            }
        }
        cout<<ans;
    }
    return 0;
}