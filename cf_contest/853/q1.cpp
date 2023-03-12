#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }
    bool possible = false;
    int i,j;
    for( i = 0;i<n;i++){
        for( j = i+1;j<n;j++){
            if(__gcd(v[i],v[j])<3){
                possible = true;
                break;
            }
        }
    }
    if(possible){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}