#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i];
    }
    int cur=1;int idx=0;
    while(cur!=n+1){
        cout<<v[idx]-cur<<endl;
        if(v[idx]==cur){
            idx++;
        }
        cur++;
    }
    return 0;
}