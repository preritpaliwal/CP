#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==3){
            cout<<"NO\n";
            continue;
        }
        if(n%2==0){
            cout<<"YES\n";
            int a = 1;
            for(int i = 0;i<n;i++){
                cout<<a<<" ";
                a = -a;
            }
            cout<<endl;
        }
        else{
            // cout<<"NO\n";
            cout<<"YES\n";
            int a = 1-(n/2);
            for(int i = 0;i<n;i++){
                cout<<a<<" ";
                // if(a<0){
                a = -a+1;
                // }
                // else{
                //     a = 
                // }
            }
            cout<<endl;
        }
    }
    return 0;
}