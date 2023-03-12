#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fo1(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
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
        vll a(n,0);
        fo0(i,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        

        ll k = LLONG_MAX;
        for(ll i = 1;i<n;i++){
            for(ll j = i-1;j<n-1;j++){
                if(j==i){
                    continue;
                }

                if(k>abs((a[j]-a[0]) - (a[n-1]-a[i]))){
                    k = abs((a[j]-a[0]) - (a[n-1]-a[i]));
                }

            }
        }

        cout<<k<<endl;
    }
    return 0;
}