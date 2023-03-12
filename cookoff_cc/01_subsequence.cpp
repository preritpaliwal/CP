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
#define vpll vector<pair<ll,ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;

bool comp(int a,int b){
    return a>b;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vll z,o;
        ll k;
        fo0(i,n){
            cin>>k;
            if(i%2==0){
                z.push_back(k);
            }
            else{
                o.push_back(k);
            }
        }

        sort(o.begin(),o.end());
        sort(z.begin(),z.end(),comp);
        k = 0;
        while(k<o.size()){
            cout<<z[k]<<" "<<o[k]<<" ";
            k++;
        }
        if(k!=z.size()){
            cout<<z[k];
        }
        cout<<endl;
        fom(i,0,o.size()-2){
            o[i] += o[i+1];
        }
        ll f = 0;
        fo0(i,o.size()){
            f += z[i]*o[i];
        }
        cout<<f<<endl;
    }

    return 0;
}