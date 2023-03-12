// link to ques : https://codeforces.com/problemset/problem/109/A

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
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
    ll rem = n%7;
    ll a[7] = {0,2,4,6,1,3,5};
    if(a[rem]/2>n/7){
        cout<<-1<<endl;
        return 0;
    }
    fo0(i,a[rem]){
        cout<<4;
    }
    fo0(i,n/7 - a[rem]/2){
        cout<<7;
    }
    return 0;
}