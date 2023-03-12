// link to ques : https://codeforces.com/problemset/problem/9/C

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=a;i>=n;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define vvll vector<vector<ll>> 
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
    ll n;
    cin>>n;
    ll d = 0,nc = n;
    while(nc!=0){
        nc/=10;
        d++;
    }
    vll v(d,1);
    ll no = 1;
    fo0(i,d-1){
        no*=10;
    }
    fo0(i,d){
        if(n/no>1){
            break;
        }
        else if(n/no==0){
            v[i] = 0;
        }
        n %= no;
        no/=10;
    }
    ll ans = 0;
    no = 1;
    fom(i,d-1,0){
        ans += v[i]*no;
        no*=2;
    }
    cout<<ans<<endl;
    return 0;
}