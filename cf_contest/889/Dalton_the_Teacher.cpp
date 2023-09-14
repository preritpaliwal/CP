#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    int n;cin>>n;
    vector<int> v(n);
    int cnt=0;
    for(int i=0;i<n;i++){cin>>v[i];if(v[i]==i+1)cnt++;}
    if(cnt==0){
        cout<<cnt<<endl;
        return;
    }
    if(cnt%2==0){
        cout<<cnt/2<<endl;
    }
    else{
        cout<<cnt/2 + 1<<endl;
    }
    return;
}

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}