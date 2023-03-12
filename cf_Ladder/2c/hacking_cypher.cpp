// link to ques : https://codeforces.com/problemset/problem/490/C

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

// ll noOfDigit(ll n){
//     ll a = 0;
//     while(n!=0){
//         a++;
//         n/=10;
//     }
//     return a;
// }


int main()
{
    fast
    string s;
    ll a[2];
    cin>>s>>a[0]>>a[1];
    ll cur = 0;
    ll index = 0;
    ll k = 0;
    ll z = -1;
    while(index<s.size()){
        cur = 10*cur + s[index++]-'0';
        if(cur<a[k]){
            continue;
        }
        cur %= a[k];
        if(cur==0){
            if(k==0){
                z = index;
            }
            k=1;
        }
    }
    string s1,s2;
    if(cur==0 && k==1){
        fo0(i,s.size()){
            if(i==z){
                while(s[i]=='0'){
                    s1 += s[i];
                    i++;
                }                
            }
            if(i>=s.size()){
                break;
            }
            if(i<z)
            s1 += s[i];
            else{
                s2 += s[i];
            }
        }
        // cout<<"s= "<<s<<" size : "<<s.size()<<endl;
        // cout<<"s1= "<<s1<<" size : "<<s1.size()<<endl;
        // cout<<"s2="<<s2<<"size : "<<s2.size()<<endl;
        if(s2.size()==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<s1<<endl<<s2;
        }
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}