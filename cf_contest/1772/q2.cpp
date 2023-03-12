#include <bits/stdc++.h>
using namespace std;

void rot(vector<int> &v){
    int a = v[0];
    v[0] = v[2];
    v[2] = v[3];
    v[3] = v[1];
    v[1] = a;
}

bool check(vector<int> &v){
    if(v[0]>=v[1]){
        return false;
    }
    if(v[2]>=v[3]){
        return false;
    }
    if(v[0]>=v[2]){
        return false;
    }
    if(v[1]>=v[3]){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> a(4);
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        bool yes = false;
        for(int i = 0;i<4;i++){
            if(check(a)){
                yes = true;
            }
            else{
                rot(a);
            }
        }
        if(yes){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}