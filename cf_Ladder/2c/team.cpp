// link to ques : https://codeforces.com/problemset/problem/401/C

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
    ll n0,n1;
    cin>>n0>>n1;
    if(n1>n0*2+2 || n0>n1+1){
        cout<<-1;
        return 0;
    }
    int prev = -1;
    int prev_p = -1;
    while(n0!=n1){
        if(prev==-1){
            if(n0>n1){
                cout<<0;
                prev_p = prev;
                prev = 0;
                n0--;
            }
            else{
                cout<<1;
                prev_p = prev;
                prev = 1;
                n1--;
            }
        }
        else{
            if(prev ==0){
                cout<<1;
                prev_p = prev;
                prev = 1;
                n1--;
            }
            else if(prev_p==prev && prev == 1){
                cout<<0;
                prev_p = prev;
                prev = 0;
                n0--;
            }
            else{
                if(n0>n1){
                    cout<<0;
                    prev_p = prev;
                    prev = 0;
                    n0--;
                }
                else{
                    cout<<1;
                    prev_p = prev;
                    prev = 1;
                    n1--;
                }
            }
        }
    }
    for(int i = 0;i<n0;i++){
        if(prev == 0){
            cout<<1<<0;
        }
        else{
            cout<<0<<1;
        }
    }
    return 0;
}
