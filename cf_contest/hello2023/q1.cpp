#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = -1;
        int firstR = -1;
        int lastL = -1;
        for(int i = 0;i<n;i++){
            if(s[i]=='R' && firstR==-1){
                firstR = i;
            }
            if(s[i]=='L'){
                lastL = i;
            }
        }
        if(firstR==-1 || lastL==-1){
            cout<<ans<<endl;
        }
        else{
            if(firstR<lastL){
                ans = 0;
                cout<<ans<<endl;
            }
            else{
                cout<<firstR<<endl;
            }
        }
    }
    return 0;
}