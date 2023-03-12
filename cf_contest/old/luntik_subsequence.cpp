#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
int main()
{
    IOS
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vll v(n);
        ll zeros = 0;
        ll ones = 0;
        fo0(i,n){
            cin>>v[i];
            if(v[i]==0){
                zeros++;
            }
            if(v[i]==1){
                ones++;
            }
        }
        cout<<ones*((ll)pow(2,zeros))<<endl;
    }
    return 0;
}