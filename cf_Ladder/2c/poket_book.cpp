// link to ques : https://codeforces.com/problemset/problem/152/C

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

string new_str(string s1,string s2,ll k){
    string s3 = s1;
    fo0(i,k){
        s3[i] = s2[i];
    }
    return s3;
}

int main()
{
    fast
    ll n,m;
    cin>>n>>m;
    vector<string> v(n);
    set<string> s;
    fo(i,0,n){
        cin>>v[i];
        s.insert(v[i]);
    }
    // ll ans = 0;
    fo0(i,n){
        fo(j,i+1,n){
            fo(k,1,m){
                // ans++;
                s.insert(new_str(v[i],v[j],k));
                s.insert(new_str(v[j],v[i],k));
            }
        }
    }
    // cout<<ans<<endl;
    cout<<s.size()%mod<<endl;
    return 0;
}