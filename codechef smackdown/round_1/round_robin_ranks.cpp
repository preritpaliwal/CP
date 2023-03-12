#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(lld i=a;i<n;i++)
#define fo0(i,n) for(lld i=0;i<n;i++)
#define fo1(i,a,n) for(lld i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
int main()
{
    IOS
    ll t; cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll left = (n*(n-1) - (n-k-1)*(n-k))/k;
        cout<< left - (left%2)<<endl;
    }
}