#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    set<string> s;
    for(int i=0;i<n;i++){
        string cur;cin>>cur;
        if(s.find(cur)==s.end()){
            reverse(cur.begin(),cur.end());
            if(s.find(cur)==s.end()){
                s.insert(cur);
            }
        }
    }
    cout<<s.size();
    return 0;
}