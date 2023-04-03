#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }
    vector<int> v;
    while(n!=1){
        if(((n+1)%4) != 0){
            v.push_back(1);
            n = (n+1)/2;
        }
        else{
            v.push_back(2);
            n = (n-1)/2;
        }
    }
    cout<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[v.size() - i-1]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}