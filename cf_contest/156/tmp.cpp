
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll pos, ll n){
    int k = 0; 
    while(1){
        pos = pos - n;
        if(pos <= 0) break;
        n--;
        k++;
    }
    return k;
}

void solve(){
    
    string s;
    ll pos;
    cin>>s; cin>>pos;

    ll n=s.size();
    ll i = find(pos, n); // max amount that can be removed
    ll itemp = n - i;
    ll sum = n * (n + 1) / 2 - itemp * (itemp + 1) / 2;
    cerr<<sum<<":sum\n";
    ll postemp = pos - sum - 1; // new pos in the string 
    cerr<<postemp<<":postemp\n";
    stack<char> stk;
    ll removed = 0;
    for(int q = 0; q<n; q++){
        if(removed >= i) {
            stk.push(s[q]); continue; 
        }
        while(!stk.empty() && removed <i && (s[q] - 'a' < stk.top() - 'a') ){
            stk.pop(); removed ++;
        }
        stk.push(s[q]);
    }
    string stemp;
    while(!stk.empty()){
        char c = stk.top();
        stemp += c;
        stk.pop();
    }
    reverse(stemp.begin(), stemp.end());
    cout<<stemp[postemp];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    // t = 9 * 10 / 2;
    // string s; cin>>s;
    while(t){
        solve();
        t--;
    }
    // solve(39, s);
}