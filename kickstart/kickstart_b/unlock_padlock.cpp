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
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
void print(vll v){
    fo0(i,v.size()){cout<<v[i]<<" ";}
    cout<<endl;}

void strip0(vector<long long> &v,long long lo,long long ro,long long &ln,long long &rn){
    long long newl = lo,newr = ro,i;
    for(i = lo;i<=ro;i++){
        if(v[i]!=0){
            newl = i;
            break;
        }
    }
    if(i==ro+1){
        ln = ro+1;
        rn = ro;
        return;
    }
    for(i = ro;i>=lo;i--){
        if(v[i]!=0){
            newr = i;
            break;
        }
    }
    ln = newl;
    rn = newr;
}

void strip1(vector<long long> &v,long long lo,long long ro,long long &ln,long long &rn){
    long long newl = lo,newr = ro,i;
    for(i = lo;i<=ro;i++){
        if(v[i]!=1){
            newl = i;
            break;
        }
    }
    if(i==ro+1){
        ln = ro+1;
        rn = ro;
        return;
    }
    for(int i = ro;i>=lo;i--){
        if(v[i]!=1){
            newr = i;
            break;
        }
    }
    rn = newr;
    ln = newl;
}

int main()
{
    fast
    int _; cin>>_;
    for(int t = 0;t<_;t++){
        cout<<"Case #"<<t+1<<": ";
        long long n,d;
        cin>>n>>d;
        vector<long long> v(n);
        for(int i  =0;i<n;i++){
            cin>>v[i];
        }
        long long l,r;
        strip0(v,(long long)0,(long long)v.size()-1,l,r);
        int ans = 0;
        while(l<r){
            ans++;
            // cout<<l<<","<<r<<endl;
            if(ans%2==1){
                strip1(v,l,r,l,r);
            }
            else{
                strip0(v,l,r,l,r);
            }
        }
        // cout<<l<<","<<r<<endl;
        if(l==r){
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}