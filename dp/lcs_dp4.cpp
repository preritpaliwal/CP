// link to ques: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

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

int lcs(string &s1,string &s2,int m,int n,string &s){
    if(m==0 || n==0){
        s = "";
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        string s3 = "";
        int ans = lcs(s1,s2,m-1,n-1,s3);
        s += s3;
        s += s1[m-1];
        return 1 + ans;
    }
    else{
        string s3 = "",s4 = "";
        int ans1 = lcs(s1,s2,m,n-1,s3);
        int ans2 = lcs(s1,s2,m-1,n,s4);
        if(ans1>ans2){
            s = s3;
            return ans1;
        }
        else{
            s = s4;
            return ans2;
        }
    }

}

int main()
{
    fast
    string s1,s2;
    cin>>s1>>s2;
    string s3 = "";
    cout<<lcs(s1,s2,s1.size(),s2.size(),s3)<<"\nstring is : "<<s3;
    return 0;
}