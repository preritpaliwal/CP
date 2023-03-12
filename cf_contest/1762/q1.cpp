#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int sum = 0;
        int minOp = 1e9;
        for(int &i:v){
            cin>>i;
            sum += i;
            int t1= i%2;
            int tmp = 0;
            while(i%2==t1){
                i/=2;
                tmp++;
            }
            minOp = min(minOp,tmp);
        }
        if(sum%2==0){
            cout<<0<<endl;
        }
        else{
            cout<<minOp<<endl;
        }
    }
}