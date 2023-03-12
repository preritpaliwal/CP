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

vll getvector(ll sum,ll n){
    // cout<<"sum="<<sum<<" n="<<n<<endl;
    if(n==0){
        vll v(1,sum);
        return v;
    }
    vll v1 = getvector(sum/2,n-1);
    vll v2 = getvector(sum-sum/2,n-1);
    vll v(pow(2,n)); 
    for(ll i=0;i<pow(2,n);i++){
        if(i<v1.size()){
            v[i] = v1[i];
        }
        else{
            v[i] = v2[i-v1.size()];
        }
    }
    return v;
}

bool equal(vll v1,vll v2){
    if(v1.size()!=v2.size()){
        return false;
    }
    for(ll i=0;i<v1.size();i++){
        if(v1[i]!=v2[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll val = 1;
        fo0(i,n){
            val*=2;
        }

        vll v(val);
        fo0(i,val){
            cin>>v[i];
        }
        ll top = *max_element(v.begin(),v.end());
        ll bot = *min_element(v.begin(),v.end());
        if(top-bot<=1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
