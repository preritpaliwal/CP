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
#define pqu priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
void print(vll v){
    fo0(i,v.size()){cout<<v[i]<<" ";}
    cout<<endl;}

struct node{
    ll val;
    ll row;
    ll col;  
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    ll n = matrix.size();
    pqu<node> pq;
    fo0(i,n){
        node n;
        n.val = matrix[i][0];
        n.row = i;
        n.col = 0;
        pq.push(n);
    }
    node ans;
    fo0(i,k){
        ans = pq.top();
        pq.pop();
        if(ans.col+1>=n){
            continue;
        }
        node n;
        n.val = matrix[ans.row][ans.col+1];
        n.row = ans.row;
        n.col = ans.col+1;
        pq.push(n);
    }
    cout<<ans.val<<endl;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
    
    }
    return 0;
}