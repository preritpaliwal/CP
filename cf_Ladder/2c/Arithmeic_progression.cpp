// link to ques : https://codeforces.com/problemset/problem/382/C

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
    if(n==1){
        cout<<-1;
        return 0;
    }
    if(n==2){
        if(v[0]==v[1]){
            cout<<1<<endl<<v[0];
        }
        else if((v[0]+v[1])%2==0){
            cout<<3<<endl<<2*v[0]-v[1]<<" "<<(v[0]+v[1])/2<<" "<<-v[0]+2*v[1];
        }
        else{
            cout<<2<<endl<<2*v[0]-v[1]<<" "<<-v[0]+2*v[1];
        }
        return 0;
    }
    ll dif = v[1]-v[0];
    ll state = 0;
    ll ind = -1;
    fo(i,2,n){
        if(dif!=v[i]-v[i-1]){
            state++;
            ind = i;
        }
    }
    if(state==0){
        if(dif==0){
            cout<<1<<endl<<v[0];
            return 0;
        }
        cout<<2<<endl<<v[0]-dif<<" "<<v[n-1]+dif;
        return 0;
    }
    if(state == 1){
        if(v[ind]-v[ind-1]==2*dif){
            cout<<1<<endl<<v[ind]-dif;
            return 0;
        }
    }
    dif = v[n-1]-v[n-2];
    state = 0;
    ind = -1;
    fo0(i,n-2){
        if(dif!=v[i+1]-v[i]){
            state++;
            ind = i;
        }
    }
    if(state==1){
        if(v[ind+1]-v[ind] == 2*(dif)){
            cout<<1<<endl<<v[ind]+dif;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
