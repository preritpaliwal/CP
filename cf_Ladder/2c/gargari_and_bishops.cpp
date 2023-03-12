// link to ques : https://codeforces.com/problemset/problem/463/C

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
    ll n;
    cin>>n;
    vll waetghjkl(n,0);
    vvll v(n,waetghjkl),sum(n,waetghjkl);
    fo0(i,n){
        fo0(j,n){
            cin>>v[i][j];
        }
    }
    ll odd_sum = -1,even_sum = -1,ox = -1,oy = -1,ex = -1,ey = -1;
    vll dec_d(2*n-1,0),inc_d(2*n-1,0);
    fo0(i,2*n-1){
        ll a,b;
        ll s = i-n+1;
        if(s>0){
            a = s;
            b = 0;
        }
        else{
            b = -s;
            a = 0;
        }
        fo0(k,n-abs(s)){
            dec_d[i]+=v[a+k][b+k];
        }
        s = i;
        if(s>=n){
            a = n-1;
            b = s- n+1;
        }
        else{
            a = s;
            b = 0;
        }
        fo0(k,n-abs(s-n+1)){
            inc_d[i] += v[a-k][b+k];
        }
    }
    fo0(i,n){
        fo0(j,n){
            ll cur_sum = dec_d[i-j+n-1]+inc_d[i+j]-v[i][j];
            // cout<<cur_sum<<" ";
            if((i+j)%2==1){
                // cout<<"o";
                if(cur_sum>odd_sum){
                    // cout<<"u";
                    odd_sum = cur_sum;
                    ox = i+1;
                    oy = j+1;
                }
            }
            else{
                // cout<<"e";
                if(cur_sum>even_sum){
                    // cout<<"u";
                    even_sum = cur_sum;
                    ex = i+1;
                    ey = j+1;
                }
            }
        }
        // cout<<endl;
    }
    cout<<odd_sum+even_sum<<endl<<ox<<" "<<oy<<" "<<ex<<" "<<ey;
    return 0;
}

/*



*/