// link to ques : https://codeforces.com/contest/776/problem/B

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

bool isPrime(ll n){
    if(n<4){
        return true;
    }
    fo(i,2,sqrt(n)+1){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    fast
    ll n;
    cin>>n;
    if(n==1){
        cout<<"1\n1";
        return 0;
    }
    else if(n==2){
        cout<<"1\n1 1";
        return 0;
    }
    cout<<2<<endl;
    fo(i,2,n+2){
        if(isPrime(i)){
            cout<<"1 ";
        }
        else{
            cout<<"2 ";
        }
    }
    return 0;
}





// 8





// 2 3 4 5 6 7 8 9 
// 1 1 2 1 2 1 2 2 