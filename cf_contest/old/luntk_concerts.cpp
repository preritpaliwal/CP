#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
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
        ll a,b,c;
        cin>>a>>b>>c;
        // c%=2;
        // if(c==0){
        //     b%=2;
        //     if(b==0){
        //         a%=2;
        //         cout<<a;
        //     }
        //     else{
        //         if(a%2==0){
        //             cout<<a;
        //         }
        //         else{
        //             cout<<1;
        //         }
        //     }
        // }
        // else{
        //     if(b%2==1){
        //         if(a%2==1){
        //             cout<<0;
        //         }
        //         else{
        //             cout<<1;
        //         }
        //     }
        //     else{
        //         if(a%2==1){
        //             cout<<0;
        //         }
        //         else{
        //             cout<<1;
        //         }
        //     }
        // }


        cout<<(a+2*b+3*c)%2;

        cout<<endl;
    }
    return 0;
}

