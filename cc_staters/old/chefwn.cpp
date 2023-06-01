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

bool isprime(int n){
    if(n==1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    fo(i,2,sqrt(n)+1){
        // cout<<i<<" for "<<n<<endl;
        if(n%i==0){
            // cout<<"divided"<<endl;
            return false;
        }
    }
    // cout<<"_____"<<n<<" is prime"<<endl;
    return true;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        if(m==1 || m==2){
            cout<<m-1<<endl;
            continue;
        }
        ll max_col = 0;
        fo(i,1,sqrt(m)+1){
            if(m%i==0){
                if(isprime(i)){
                    max_col++;
                    // cout<<"i = "<<i<<endl;
                }
                if(isprime(m/i)){
                    max_col++;
                    // cout<<"i="<<m/i<<endl;
                    if(i*i==m){
                        max_col--;
                    }
                }
            }
        }
        // cout<<"max_col = "<<max_col<<endl;
        fom(i,1,max_col){
            if(n%i==0){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}