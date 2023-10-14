#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;string s;cin>>s;
        vector<int> kmp(n+1,-1);
        int i=0,j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j])j=kmp[j];
            j++;i++;
            kmp[i]=j;
        }
        if(kmp[n]==0)cout<<-1<<"\n";
        else{
            string ans;
            for(int k=2;k<n;k++){
                // cerr<<kmp[k]<<" ";
                if(kmp[k]==kmp[n]){ans=s.substr(0,kmp[n]);break;}
            }
            if(ans.empty()){
                if(kmp[kmp[n]]==0){
                    cout<<"-1\n";
                }
                else{
                    cout<<s.substr(0,kmp[kmp[n]])<<"\n";
                }
            }
            else{
                cout<<ans<<"\n";
            }
        }
        // cerr<<"\n";
    }
}