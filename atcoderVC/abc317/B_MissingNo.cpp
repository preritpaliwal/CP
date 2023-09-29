#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]!=1){
            cout<<v[i-1]+1;
            break;
        }
    }
    return 0;
}