#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;

    string s1 = s,t1=t;
    sort(s1.begin(),s1.end());
    sort(t1.begin(),t1.end());
    int all = 1;
    for(int i =0;i<n;i++){
        if(s1[i]!=t1[i]){
            all=0;
        }
    }

    if(all==0){
        cout<<"NO\n";
    }
    else{
        if(n==1){
            if(s[0]==t[0]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(n==2){
            if(s[0]==t[0] && s[1]==t[1]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(n==3){
            if(s[0]==t[0] && s[1]==t[1] && s[2]==t[2]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(n==4){
            if(s[1]==t[1] && s[2]==t[2]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(n==5){
            if(s[2]==t[2]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"YES\n";
        }
    }

}

int  main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}