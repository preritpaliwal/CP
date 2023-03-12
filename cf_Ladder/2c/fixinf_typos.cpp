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
    string s1,s2 = "";
    cin>>s1;
    if(s1.size()<=2){
        cout<<s1;
        return 0;
    }
    s2 += s1[0];
    s2 += s1[1];
    ll j = 2;
    fo(i,2,s1.size()){
        // cout<<"i = "<<i<<endl;
        if(s2[j-1]==s2[j-2] && s1[i]==s2[j-1]){
            // cout<<"skipping : "<<s1[i]<<endl;
            continue;
        }
        else{
            s2 += s1[i];
            j++;
        }
    }
    // cout<<s2<<"\n";
    if(s2.size()<=3){
        cout<<s2;
        return 0;
    }
    string s3 = "";
    s3 += s2[0];
    s3 += s2[1];
    s3 += s2[2];
    j = 3;
    fo(i,3,s2.size()){
        if(s3[j-3]==s3[j-2] && s3[j-1]==s2[i]){
            // cout<<"skipping 2 : "<<s2[i]<<endl;
            continue;
        }
        else{
            s3 += s2[i];
            j++;
        }
    }
    cout<<s3<<endl;
    return 0;
}

/*

3 identical , 2 identical couple

*/