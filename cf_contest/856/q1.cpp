#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string ixs[n-1];
    bool palin = true;
    for(int i = 0;i<2*n-2;i++){
        string s;
        cin>>s;
        if(ixs[s.size()-1].size()==0){
            ixs[s.size()-1] = s;
        }
        else{
            for(int i = 0;i<s.size();i++){
                if(s[i]!=ixs[s.size()-1][s.size()-1-i]){
                    palin = false;
                }
            }
        }
    }
    if(palin){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}