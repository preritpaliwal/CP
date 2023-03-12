#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    for(int i = 'a';i<='z';i++){
        int multi = 1;
        int prev = -1;
        for(int j = 0;j<n;j++){
            if(s[j]==i){
                if(prev==-1){
                    ans += 1LL*(j+1);
                    prev = j;
                    multi = j+1;
                }
                else{
                    ans += 1LL*(multi)*(j-prev-1);
                    multi = j-prev;
                    prev = j;
                }
                cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
        if(prev!=-1){
            ans += 1LL*(n-prev-1)*(multi);
            cout<<"ans: "<<ans<<endl;
        }
    }
    cout<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}