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

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vll v(n);
        ll maxdif = 0;
        fo(i,0,n){
            cin>>v[i];
            v[i]-=(i+1);
            if(v[i]>maxdif){
                maxdif=v[i];
            }
        }
        cout<<maxdif<<endl;

    }
    return 0;
}