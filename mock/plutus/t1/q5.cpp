#include <bits/stdc++.h>
using namespace std;
using ll=long long;


set<ll> get(string s){
    set<ll> se;
    // cerr<<s<<"\n";
    se.insert(stoll(s));
    if(s.size()<2){
        return se;
    }
    for(ll i=0;i<s.size();i++){
        se.insert(stoll(string {s[i]}));
        set<ll> un=get(s.substr(0,i)+s.substr(i+1));
        for(auto &it:un){
            se.insert(it);
        }
    }
    return se;
}

int main(){
    string x,y;cin>>x>>y;
    set<ll> s1=get(x);
    set<ll> s2=get(y);
    set<ll> tmp;
    for(auto &it:s2){
        // cerr<<it<<" ";
        if(s1.find(it)!=s1.end()){
            if(it!=0){
                tmp.insert(it);
            }
        }
    }
    if(tmp.empty()){
        cout<<0<<"\n";
    }
    else{
        cout<<tmp.size()<<"\n";
    }
}