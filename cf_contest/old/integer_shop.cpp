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

struct seg{
    ll min;
    ll max;
    ll cost;
};

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<seg> v(n);
        fo0(i,n){
            cin>>v[i].min>>v[i].max>>v[i].cost;
        }
        ll i_min=0,i_max=0,prev_c = v[0].cost,prev_r = v[0].max-v[0].min;
        cout<<v[0].cost<<endl;
        fo(i,1,n){
            if(v[i].min<v[i_min].min){
                i_min = i;
            }
            else if(v[i].min==v[i_min].min && v[i].cost<v[i_min].cost){
                i_min = i;
            }
            if(v[i].max>v[i_max].max){
                i_max = i;
            }
            else if(v[i].max==v[i_max].max && v[i].cost<v[i_max].cost){
                i_max = i;
            }
            if(prev_r<v[i].max-v[i].min){
                prev_r = v[i].max-v[i].min;
                prev_c = v[i].cost;
            }
            else if(prev_r==v[i].max-v[i].min && prev_c<v[i].cost){
                prev_c = v[i].cost;
            }
            if(prev_r<v[i_max].max-v[i_min].min){
                cout<<v[i_max].cost+v[i_min].cost<<endl;
            }
            else{
                cout<<prev_c<<endl;
            }
        }
    }
    return 0;
}