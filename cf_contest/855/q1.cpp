#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int state = 0;
    for(int i = 0;i<s.size();i++){
        if((s[i]=='m' || s[i]=='M') && (state==0 || state==1)){
            state = 1;
        }
        else if((s[i]=='e' || s[i]=='E') && (state==1 || state==2)){
            state=2;
        }
        else if((s[i]=='o' || s[i]=='O') && (state==2 || state==3)){
            state=3;
        } 
        else if((s[i]=='w' || s[i]=='W') && (state==3 || state==4)){
            state=4;
        }
        else{
            state =-1;
            break;
        }
    }
    if(state==4){
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