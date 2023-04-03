#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int minans = 0,maxans = 0;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        vector<int> curmin(m,0);
        for(int i = 0;i<m;i+=4){
            if(i==0){
                int ones = 0;
                int cons = 0;
                for(int j = 0;j<4;j++){
                    if(s[i]=='1'){
                        ones++;
                    }
                }
                int zero = 4-ones;
                for(int i = 0;i<3;i++){
                    if(s[i]=='1' && s[i+1]=='1'){
                        cons++;
                        i++;
                    }
                }
                
            }
        }
    }
}