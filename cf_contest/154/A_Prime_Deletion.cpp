#include <bits/stdc++.h>
using namespace std;
using ll=long long;


void solve(){
    string s;
    cin>>s;
    int ans=-1;
    for(int i=0;i<9;i++){
        if(s[i]=='1'){
            if(ans==-1){
                ans=i;
            }
            else{
                cout<<31<<endl;
                return;
            }
        }
        else if(s[i]=='3'){
            if(ans==-1){
                ans=i;
            }
            else{
                cout<<13<<endl;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
}