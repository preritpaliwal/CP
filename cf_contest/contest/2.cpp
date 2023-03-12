#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(m%4==0){
            cout<<"NO\n";
            continue;
        }
        if(m%4==2){
            cout<<"YES\n";
            for(int i = 1;i<=n;i+=2){
                if((i+1)%4==2){
                    cout<<i+1<<" "<<i<<"\n";
                }
                else{
                    cout<<i<<" "<<i+1<<"\n";
                }
            }
        }
        else{
            cout<<"YES\n";
            for(int i = 1;i<=n;i+=2){
                cout<<i<<" "<<i+1<<"\n";
            }
        }
    }
    return 0;
}
