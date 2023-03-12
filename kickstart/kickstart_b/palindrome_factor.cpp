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

bool isPalindrome(int n){
    vector<int> v;
    while(n!=0){
        v.push_back(n%10);
        n/=10;
    }
    for(int i = 0;i<v.size();i++){
        if(v[i]!=v[v.size()-1-i]){
            return false;
        }
    }
    return true;
}

int main()
{
    fast
    int _; cin>>_;
    for(int t = 0;t<_;t++){
        cout<<"Case #"<<t+1<<": ";
        long long n,ans = 0;
        cin>>n;
        for(long long i = 1;i*i<n;i++){
            if(n%i==0){
                if(isPalindrome(i)){
                    ans++;
                }
                if(i*i!=n){
                    if(isPalindrome(n/i)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}