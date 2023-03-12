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
    cout<<endl;
}



int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vll v(n);
        fo0(i,n){cin>>v[i];}
        sort(v.begin(),v.end());
        ll med;
        if(v.size()%2){
            med  =  v[(n-1)/2];
        }
        else{
            med =  v[n/2 -1]; 
        }
        ll sum =  accumulate(v.begin(),v.end(),0);
        ll n_ops = 0;
        // ll x = v.size()%2==0 ? -1 : 0;
        cout<<sum<<" "<<med*n <<endl;
        if(med*n==sum){
            cout<<0<<endl;
            continue;
        }
        else if(sum>med*n){
            n_ops = (sum-med*n)/(n-1);
            sum += n_ops;
            med += n_ops;
            cout<<sum<<" "<<med*n <<endl;
            while(sum>med*n){
                cout<<sum<<" "<<med*n <<endl;
                n_ops++;
                med++;
                sum++;
            }
            cout<<sum<<" "<<med*n <<"nop = "<<n_ops<<endl;
        }
        if(med*n==sum){
            cout<<n_ops<<endl;
        }
        else{
            n_ops += (med*n-sum);
            cout<<n_ops<<endl;
        }
    }
    return 0;
}

