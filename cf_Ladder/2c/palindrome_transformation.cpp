//link to ques : https://codeforces.com/problemset/problem/486/C

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
    ll n,k;
    cin>>n>>k;
    k--;
    string s;
    cin>>s;
    if(n==1){
        cout<<0;
        return 0;
    }
    vll dif;
    ll ans = 0;
    fo0(i,n/2){
        dif.push_back(min(abs(s[i]-s[n-1-i]),26-abs(s[i]-s[n-1-i])));
        ans += dif[i];
    }
    // cout<<"min ans"<<ans<<endl;
    ll l = 0;
    ll r = dif.size()-1;
    fo0(i,r+1){
        // cout<<"dif[i] : "<<dif[i]<<endl;
        if(dif[i]==0){
            l++;
        }
        else{
            break;
        }
    }
    fom(i,l,r){
        // cout<<"diff[i] = "<<dif[i]<<endl;
        if(dif[i]==0){
            r--;
        }
        else{
            break;
        }
    }
    if(l>r){
        cout<<0;
        return 0;
    }
    // cout<<"l,r = "<<l<<" "<<r<<endl;
    if(2*k<n){
        ans += r-l + min(abs(k-l),abs(r-k));
        // cout<<"2*k<n"<<k-l<<" "<<r-k<<endl;
    }
    else{
        l = n-1-l;
        r = n-1-r;
        ans += l-r + min(abs(l-k),abs(k-r));
        // cout<<"else"<<l-k<<" "<<k-r<<endl;
    }
    cout<<ans;
    return 0;
}