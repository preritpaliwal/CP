// link to ques : https://www.codechef.com/SNCKQL21/problems/TESTSERIES

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int k = 0;
        int a;
        for(int i = 0;i<5;i++){
            cin>>a;
            if(a==1){
                k++;
            }
            else if(a==2){
                k--;
            }
        }
        if(k==0){
            cout<<"DRAW\n";
        }
        else if(k>0){
            cout<<"INDIA\n";
        }
        else{
            cout<<"ENGLAND\n";
        }
    }
    return 0;
}