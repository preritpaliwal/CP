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
    int n;
    cin>>n;
    vpll v(n,mp(0,0));
    vll index;
    int ut = 0,lt = 0;
    fo0(i,n){
        cin>>v[i].F>>v[i].S;
        ut += v[i].F;
        lt += v[i].S;
        if((v[i].F %2) + (v[i].S %2) == 1){
            index.pb(i);
        }
    }

    if(lt%2==0){
        if(ut%2==0){
            cout<<0;
        }
        else{
            cout<<-1;
        }
    }
    else{
        if(ut%2==0){
            cout<<-1;
        }
        else{
            if(index.size()>0){
                cout<<1;
            }
            else{
                cout<<-1;
            }
        }
    }
}