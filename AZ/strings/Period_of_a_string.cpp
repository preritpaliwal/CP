#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    int T=t;
    while(t--){
        cout<<"Test case #"<<T-t<<"\n";
        int n;cin>>n;
        string s;cin>>s;
        vector<int> kmp(n+1,-1);
        int i=0,j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j])j=kmp[j];
            i++;j++;kmp[i]=j;
        }
        for(int i=1;i<n;i++){
            int exp=i+1-kmp[i+1];
            if(exp!=i+1 && (i+1)%exp==0){
                cout<<i+1<<" "<<(i+1)/exp<<"\n";
            }
        }
        cout<<"\n";
    }
}