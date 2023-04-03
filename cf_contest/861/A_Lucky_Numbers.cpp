#include <bits/stdc++.h>
using namespace std;

int getLuck(string s){
    int maxi = 0,mini = 0;
    for(int i = 1;i<s.size();i++){
        if(s[i]<s[mini]){
            mini = i;
        }
        if(s[i]>s[maxi]){
            maxi = i;
        }
    }
    return s[maxi]-s[mini];
}

void solve(){
    int l,r;
    cin>>l>>r;
    int maxno = -1;
    int luck = -1;
    for(int i = 0;i<101;i++){
        if(i+l>r){
            break;
        }
        int curLuck = getLuck(to_string(i+l));
        if(curLuck>luck){
            luck = curLuck;
            maxno = i+l;
        }
    }
    cout<<maxno<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}