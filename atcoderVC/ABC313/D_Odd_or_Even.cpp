#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n+1);
    bool flip=false;
    int sum=0;
    for(int i=1;i<=k+1;i++){
        cout<<"? ";
        for(int j=1;j<=k+1;j++){
            if(i!=j){
                cout<<j<<" ";
            }
        }
        cout<<endl;
        int res;cin>>v[i];
        if(i==k+1){
            if(sum%2!=v[i]){
                flip=true;
                v[i]^=1;
                v[i-1]^=1;
            }
        }
        sum+=v[i];
    }
    int parity=0;
    for(int i=1;i<k;i++){
        if(flip==true)v[i]=1^v[i];
        parity^=v[i];
    }
    for(int i=k+2;i<=n;i++){
        cout<<"? "<<i<<" ";
        for(int j=1;j<k;j++){
            cout<<j<<" ";
        }
        cout<<endl;
        int res;cin>>res;
        v[i]=res^parity;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}