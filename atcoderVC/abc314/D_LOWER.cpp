#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;string s;cin>>s;
    int q;cin>>q;
    set<int> cnst;
    int state=0;
    while(q--){
        int a,b;cin>>a>>b;
        char c;cin>>c;
        if(a==1){
            s[b-1]=c;
            cnst.insert(b-1);
        }
        else if(a==2){
            state=2;
            cnst.clear();
        }
        else if(a==3){
            state=1;
            cnst.clear();
        }
    }
    for(int i=0;i<n;i++){
        char c=s[i];
        if(cnst.find(i)==cnst.end()){
            if(state==2 && c<'a'){
                c=c+'a'-'A';
            }
            else if(state==1 && c>='a'){
                c=c-'a'+'A';
            }
        }
        cout<<c;
    }
    return 0;
}