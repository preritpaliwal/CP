#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int minans = 0,maxans = 0;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        int ones = 0;
        for(int i = 0;i<m;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        int c = 0;
        for(int i = 0;i<m-1;i++){
            if(s[i]=='1' && s[i+1]=='1'){
                c++;
                i++;
            }
        }
        minans += ones - min(m/4,c);
        c = 0;
        for(int i = 0;i<m-1;i++){
            if(!(s[i]=='1' && s[i+1]=='1')){
                c++;
                i++;
            }
        }
        maxans += ones - max(0,m/4-c);
    }
    cout<<minans<<" "<<maxans<<endl;
}

