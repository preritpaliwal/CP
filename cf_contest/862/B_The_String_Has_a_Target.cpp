#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>> n;
    string s;
    cin>>s;
    char prev = s[0];
    int change = -1;
    for(int i = 1;i<n;i++){
        if(change==-1){
            if(s[i]<=prev){
                change = i;
            }
        }
        else{
            if(s[i]<=s[change]){
                change = i;
            }
        }
    }
    // cout<<change<<endl;
    if(change==-1){
        cout<<s<<endl;
    }
    else{
        char tmp;
        for(int i = 0;i<=change;i++){
            if(i==0){
                tmp = s[i];
                s[i] = s[change];
            }
            else{
                char tmp2 = s[i];
                s[i] = tmp;
                tmp = tmp2;
            }
        }
        cout<<s<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}