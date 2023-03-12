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
#define vpll vector<pair<ll,ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;

int possible(int i,int j,int n,vector<vll> &memo){
    if(i>=n){
        return 0;
    }
    if(j>=n){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    else if(memo[i][j]!=-1){
        return memo[i][j];
    }
    else{
        if(possible(i+1,j,n,memo) || possible(i,j+1,n,memo)){
            memo[i][j] = 1;
        }
        else{
            memo[i][j] = 0;
        }
    }
    return memo[i][j];
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vpll v(n);
        fo0(i,n){
            cin>>v[i].F>>v[i].S;
        }
        sort(v.begin(),v.end());
        stack<pair<int,int>> q;
        q.push(mp(n-1,n-1));
        bool found = false;
        while(!q.empty()){
            pair<int,int> p = q.top();
            q.pop();
            if(p.F==0 && p.S==0){
                found = true;
                break;
            }
            if(p.S-1>=0 && memo[p.F][p.S-1]==-1){
                q.push(mp(p.F-1,p.S));
            }
            if(p.S-1>=0 && memo[p.F][p.S-1]==-1){
                q.push(mp(p.F-1,p.S-1));
            }
        }
        if(found){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        // cout<<(possible(0,0,n,memo) ? "YES\n" : "NO\n");
    }
    return 0;
}