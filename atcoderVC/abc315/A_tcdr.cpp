#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string s,ans;cin>>s;
    for(auto c:s){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')continue;
        ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}