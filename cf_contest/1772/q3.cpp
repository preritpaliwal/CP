#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>k>>n;
        int ch = -1;
        for(int i = k;i>=1;i--){
            if(i*(i+1)<2*n){
                ch = i;
                break;
            }
        }
        int q = 1;
        int p = 1;
        for(int i = 0;i<k;i++){
            if(q<=ch){
                cout<<p<<" ";
                p+=q;
                q++;
            }
            else{
                cout<<p++<<" ";
            }
        }
        cout<<endl;
    }
}