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
        ll ans = 0;
        fo0(i,n-2){
            ll curmid = i+1;
            fo(j,i+2,n){
                if(curmid+1!=j){
                    ll mid = (v[i]+v[j])/2;
                    while(v[curmid+1]-mid < 0){
                        curmid++;
                    }
                    if(v[curmid+1]-mid <= mid - v[curmid]){
                        curmid++;
                    }
                }
                ll val =  -(v[curmid]-v[i])*(v[curmid]-v[j]);
                cout<<"i,j,curmid,val  : "<<i<<" "<<j<<" "<<curmid<<" "<<val<<endl;
                ans+=val;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
1 4 5 6 9


1 4 5
1 4 5 6 9

4 5 6
4 5 6 9

4 5 7


*/