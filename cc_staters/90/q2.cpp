#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto c:s){
        mp[c]++;
    }
    bool ispalin = false;
    int ones = 0;
    for(auto p:mp){
        // cout<<"p: "<<p.first<<" "<<p.second<<endl;
        if(p.second%2 ==1){
            ones++;
        }
    }
    if(ones==1 && n%2==1){
        ispalin = true;
    }
    else if(ones==0 && n%2 == 0){
        ispalin = true;
    }
    else{
        cout<<0<<"\n";
        return;
    }
    if(ispalin){
        if(ones==0){
            cout<<1<<endl;
            return;
        }
        else{
            int twos = 0;
            for(auto p:mp){
                if(p.second%2 == 0){
                    twos++;
                }
            }
            if(twos>0){
                cout<<1<<endl;
                return;
            }
            
            cout<<2<<endl;
            return;
        }
    }
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}