#include<bits/stdc++.h>
using namespace std;
using ll=long long;



void solve(){
    ll n, m;
    cin>>n>>m;
    vector<string> v(n);
    for(string &i:v) cin>>i;
    vector<ll> row(n,0), col(m,0);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(v[i][j]=='U'){
                row[i]++;
            }
            if(v[i][j]=='L'){
                col[j]++;
            }
        }
    }
    for(ll i=0; i<n; i++){
        if(row[i]%2==1){
            cout<<"-1"<<endl;
            return;
        }
    }
    for(ll i=0; i<m; i++){
        if(col[i]%2==1){
            cout<<"-1"<<endl;
            return;
        }
    }
    ll rowcnt = 0, colcnt = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(v[i][j]=='U'){
                if(rowcnt%2==0){
                    v[i][j] = 'W';
                    v[i+1][j] = 'B';
                }
                else{
                    v[i][j] = 'B';
                    v[i+1][j] = 'W';
                }
                rowcnt++;
            }
        }
    }
    for(ll j=0; j<m; j++){
        for(ll i=0; i<n; i++){
            if(v[i][j]=='L'){
                if(colcnt%2==0){
                    v[i][j] = 'W';
                    v[i][j+1] = 'B';
                }
                else{
                    v[i][j] = 'B';
                    v[i][j+1] = 'W';
                }
                colcnt++;
            }
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}

