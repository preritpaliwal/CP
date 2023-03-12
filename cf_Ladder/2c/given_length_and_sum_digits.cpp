// link to ques : https://codeforces.com/problemset/problem/489/C

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

// int getmax(int s,int m,vll &maxno){
//     if(m==1){
//         if(s>9){
//             return 0;
//         }
//         else{
//             maxno[m-1] = s;
//             return 1;
//         }
//     }
//     if(s==0){
//         maxno[m-1] = 0;
//         return 1;
//     }
//     fom(i,9,0){
//         if(getmax(s-i,m-1,maxno)){
//             maxno[m-1] = i;
//             return 1;
//         }
//     }
// }

int main()
{
    fast
    ll m,s;
    cin>>m>>s;
    if(9*m<s || (s==0 & m>1)){
        cout<<"-1 -1";
        return 0;
    }
    if(s==0){
        cout<<"0 0";
        return 0;
    }
    vll maxno(m,-1);
    // getmax(s,m,maxno);
    fo0(i,m){
        if(s>=9){
            maxno[i] = 9;
            s -=9;
            // cout<<9;
        }
        else if(s==0){
            maxno[i] = 0;
            // cout<<0;
        }
        else{
            maxno[i] = s;
            // cout<<s;
            s -=s;
        }
    }
    if(maxno[m-1]!=0){
        fo0(i,m){
            cout<<maxno[m-1-i];
        }
        // return 0;
        cout<<" ";
        fo0(i,m){
            cout<<maxno[i];
        }
        return 0;
    }
    // maxno[m-1] = 1;
    cout<<1;
    bool once = true;
    fo(i,1,m){
        if(maxno[m-1-i]>0 && once){
            cout<<maxno[m-1-i]-1;
            once = false;
            continue;
        }
        cout<<maxno[m-1-i];
    }
    cout<<" ";
    fo0(i,m){
        cout<<maxno[i];
    }
    return 0;
}