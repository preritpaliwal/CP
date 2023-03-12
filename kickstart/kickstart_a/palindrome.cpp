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

string toBin(ll n,ll pos){
    string s = "";
    fo0(i,pos){
        s += (n%2==1)?'1':'0';
        n/=2;
    }
    return s;
}

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    ll l = 0;
    ll h = str.size() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            // printf("%s is not a palindrome\n", str);
            
            return false;
        }
    }
    return true;
    // printf("%s is a palindrome\n", str);
}

bool checkPalin(string s, vll pos,string s1){
    // cout<<"happy to be here"<<endl<<"s1 = "<<s1<<endl;
    if(s.size()<5){
        return true;
    }
    ll k = 0;
    fo0(i,s.size()){
        if(s[i]=='?'){
            s[i] = s1[k++];
        }
    }
    for(ll size = 5;size<=s.size();size++){
        for(ll start = 0;start+size<=s.size();start++){
            if(isPalindrome(s.substr(start,size))){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    fast
    int t; cin>>t;
    fo0(T,t){
        cout<<"Case #"<<T+1<<": ";
        string s;
        ll n;
        cin>>n;
        cin>>s;
        vll pos;
        fo0(i,n){
            if(s[i]=='?'){
                pos.push_back(i);
            }
        }
        // print(pos);
        bool possible = false;
        ll p = 1;
        fo0(i,pos.size()){
            p*=2;
        }
        fo0(i,p){
            if(!checkPalin(s,pos,toBin(i,pos.size()))){
                possible=true;
                break;
            }
        }
        if(possible){
            cout<<"POSSIBLE\n";
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}