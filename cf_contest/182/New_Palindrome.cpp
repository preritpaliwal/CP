#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int i = 1;
    int j = (int)s.size()-2;
    int dif = 0;
    while(i<j){
        if(s[i]!=s[0]){
            dif++;
            break;
        }
        i++;
        j--;
    }
    if(dif>0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
}


int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}