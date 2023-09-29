#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string s;cin>>s;int n=s.size();
    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            bool palin=true;
            int len=(i-j+1);
            for(int k=0;k<len/2;k++){
                if(s[j+k]!=s[i-k])palin=false;
            }
            if(palin)ans=max(ans,len);
        }
    }
    cout<<ans<<endl;
    return  0;
}