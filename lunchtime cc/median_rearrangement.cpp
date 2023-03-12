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

ll cost(vll med,vll v){
    ll c = 0;
    fo0(i,med.size()){
        c += v[med[i]];
    }
    return c;
}

void correct(vll &med){
    // cout<<"correcting"<<endl;
    fo(i,1,med.size()-1){
        med[i] = med[i-1]+1;
    }
    // cout<<"still\n";
    ll maxgap = (med.size()/2);
    for(ll i = med.size()-2;i>=0;i--){
        // cout<<"there"<<endl;
        if(med[i+1] > med[i] + maxgap+1){
            // cout<<"here"<<endl;
            med[i] = med[i+1]-1-maxgap;
        }
    }
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        // vll temp(n);
        // vvll v(n,temp);
        vll v(n*n);
        fo0(i,n){
            fo0(j,n){
                // cin>>v[i][j];
                cin>>v[i*n + j];
            }
        }
        sort(v.begin(),v.end());
        vll med(n);
        fo0(i,n){
            med[i] = n*(n/2) + i;
        }
        // cout<<"med : \n";
        // print(med);
        ll l = n/2;
        ll r = n*(n/2);
        vll ltemp = med;
        vll temp = med;
        bool possible = false;
        // cout<<"temp  :\n";
        while(l<=r){
            ll mid = (l+r)/2;
            temp[0] = mid;
            correct(temp);
            // print(temp);
            if(cost(temp,v)<=k){
                possible = true;
                l = mid+1;
                ltemp = temp;
            }
            else{
                r = mid-1;
                // rtemp = temp;
            }
        }
        if(!possible){
            cout<<-1<<endl;
        }
        else{
            cout<<v[ltemp[0]]<<endl;
        }
    }
    return 0;
}

/*

1 5 9  16
2 6 11 17
3 8 13 24
3 9 15 32

*/