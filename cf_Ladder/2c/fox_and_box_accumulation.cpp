// link to ques : https://codeforces.com/problemset/problem/388/A

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
    vll v(n);
    fo0(i,n){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll l = 1,r = n,mid,ans = -1;
    while(l<=r){
        mid = (l+r)/2;
        // cout<<mid<<endl;
        bool possible = true;
        fo0(i,mid){
            ll index = 0;
            while(index*mid+i<n){
                if(index>v[index*mid+i]){
                    possible = false;
                    break;
                }
                index++;
            }
        }
        if(possible){
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*

*/