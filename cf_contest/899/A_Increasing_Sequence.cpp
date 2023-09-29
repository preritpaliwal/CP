#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    int n;cin>>n;vector<int> v(n);for(int &i:v)cin>>i;
    int cur=1;
    for(int i=0;i<n;i++){
        if(v[i]==cur){
            cur++;
        }
        cur++;
    }
    cout<<cur-1<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}