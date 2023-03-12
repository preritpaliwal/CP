// link to ques : https://codeforces.com/problemset/problem/431/C

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
vll memo(101,-1);
ll dp(ll n,ll k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(memo[n]==-1){
        fo(i,1,k+1){
            memo[n]+= dp(n-i,k);
        }
        memo[n]++;
    }
    return memo[n]%mod;
}

void reset(){
    fo0(i,memo.size()){
        memo[i] = -1;
    }
}

int main()
{
    fast
    ll n,k,d;
    cin>>n>>k>>d;
    ll ans = (dp(n,k)%mod);
    reset();
    ans -= (dp(n,d-1)%mod);
    if(ans<0){
        cout<<mod+ans;
    }
    else{
        cout<<ans;
    }
    return 0;
}