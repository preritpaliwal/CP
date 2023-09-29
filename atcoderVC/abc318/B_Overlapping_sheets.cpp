#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    vector<vector<int>> v(100,vector<int> (100,0));
    int n;cin>>n;
    while(n--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        for(int i=a;i<b;i++){
            for(int j=c;j<d;j++){
                v[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            ans+=v[i][j];
        }
    }
    cout<<ans<<endl;
}