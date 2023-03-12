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
int main()
{
    fast
    int t; cin>>t;
    for(int _ = 0;_<t;_++){
        cout<<"Case #"<<_+1<<": ";
        long long r,a,b;
        cin>>r>>a>>b;
        double ans = 0;
        int itr = 0;
        long long temp = r;
        while(temp>=1){
            itr++;
            ans += temp*temp;
            if(itr%2==1){
                temp*=a;
            }
            else{
                temp/=b;
            }
            // cout<<ans<<" "<<itr<<endl;
        }
        cout<<fixed<<setprecision(6)<<(M_PI)*(ans)<<endl;
    }
    return 0;
}