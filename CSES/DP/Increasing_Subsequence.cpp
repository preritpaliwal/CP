#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio
    int n;cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int> lis;
    lis.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(lis.back()<v[i]){
            lis.push_back(v[i]);
        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(),v[i]);
            *it=v[i];
        }
    }
    cout<<lis.size()<<endl;
}