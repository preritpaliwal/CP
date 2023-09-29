#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    vector<int> cnt(3,1e9);
    int n;cin>>n;
    string s;cin>>s;
    int idx=0;
    for(char c:s){
        idx++;
        cnt[c-'A']=min(cnt[c-'A'],idx);
    }
    cout<<max(cnt[0],max(cnt[1],cnt[2]));
    return 0;
}