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
        
        // ll i_min = 0;
        // ll i_max = 0;

        // fo(i,1,n){
        //     if(a[i]>a[i_max]){
        //         i_max = i;
        //     }
        //     if(a[i]<a[i_min]){
        //         i_min = i;
        //     }
        // }

        // ll arr[n-2][2];
        // int z = 0;
        // fo0(i,n){
        //     if(i==i_min || i == i_max){
        //         z++;
        //         continue;
        //     }

        //     arr[i-z][0] = a[i]-a[i_min];
        //     arr[i-z][1] = -a[i]+a[i_max];
        // }

        sort(a.begin(),a.end());
        ll k = LLONG_MAX;
        fo0(i,n-1){
            if(k > abs((a[i]-a[0]) - (a[n-1]-a[i+1]))){
                k = abs((a[i]-a[0]) - (a[n-1]-a[i+1]));
            }
            if(k==0){
                cout<<k<<endl;
                break;
            }
        }

        if(k==0){
            continue;
        }

        fo(i,2,n-1){
            if(k > abs((a[i]-a[0]) - (a[n-1]-a[i-1]))){
                k = abs((a[i]-a[0]) - (a[n-1]-a[i-1]));
            }
            if(k==0){
                break;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}