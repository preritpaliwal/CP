#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    v.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]^=v[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        int val = v[r]^v[l-1];
        cout<<val<<endl;
    }
}