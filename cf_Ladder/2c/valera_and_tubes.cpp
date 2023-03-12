// link to ques : https://codeforces.com/problemset/problem/441/C

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

ll n,m,k;
void print(int i,int j){
    cout<<i<<" "<<j<<" ";
}

void update(ll &i,ll &j,ll &dir){
    if(j==m && dir==1){
        dir = -1;
        i++;
    }
    else if(j==1 && dir==-1){
        dir=1;
        i++;
    }
    else{
        j+=dir;
    }
}

int main()
{
    fast
    cin>>n>>m>>k;
    ll i = 1,j=1,dir = 1;
    fo0(cur,k){
        if(cur+1!=k){
            cout<<2<<" ";
            print(i,j);
            update(i,j,dir);
            print(i,j);
            update(i,j,dir);
        }
        else{
            cout<<m*n-2*cur<<" ";
            while(true){
                if(i>n){
                    break;
                }
                print(i,j);
                update(i,j,dir);
            }
        }
        cout<<endl;
    }
    return 0;
}