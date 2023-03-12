#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define pll pair<ll,ll>
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

ll get(ll x,ll y){
    if(x>0){
        cout<<"1 "<<x<<" R\n";
    }
    else if(x<0){
        cout<<"1 "<<-x<<" L\n";
    }
    if(y>0){
        cout<<"1 "<<y<<" U\n";
    }
    else if(y<0){
        cout<<"1 "<<-y<<" D\n";
    }
    cout<<"2\n";
    x = -x;
    y = -y;
    if(x>0){
        cout<<"1 "<<x<<" R\n";
    }
    else if(x<0){
        cout<<"1 "<<-x<<" L\n";
    }
    if(y>0){
        cout<<"1 "<<y<<" U\n";
    }
    else if(y<0){
        cout<<"1 "<<-y<<" D\n";
    }
    cout<<"3\n";
}

bool comp(pll p1,pll p2){
    return abs(p1.F)+abs(p1.S)<abs(p2.F) + abs(p2.S);
}

int main()
{
    fast
    ll n,ans = 0;
    cin>>n;
    vpll v(n);
    fo0(i,n){
        cin>>v[i].F>>v[i].S;
        if(v[i].F!=0){
            ans+=2;
        }
        if(v[i].S!=0){
            ans+=2;
        }
        ans+=2;
    }
    cout<<ans<<endl;
    sort(v.begin(),v.end(),comp);
    fo0(i,n){
        get(v[i].F,v[i].S);
    }
    return 0;
}