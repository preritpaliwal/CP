#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    for(int &i:a)cin>>i;for(int &i:b)cin>>i;
    for(int i=0;i<n;i++){
        c[i]=(a[i]^a[(i+1)%n]);
        d[i]=(b[i]^b[(i+1)%n]);
    }
    vector<int> tmp;
    tmp.insert(tmp.end(),d.begin(),d.end());
    tmp.push_back(-1);
    tmp.insert(tmp.end(),c.begin(),c.end());
    tmp.insert(tmp.end(),c.begin(),c.end());
    vector<int> kmp(tmp.size()+1,-1);
    int ni=0,nj=-1;
    while(ni<tmp.size()){
        while(nj!=-1 && tmp[ni]!=tmp[nj])nj=kmp[nj];
        ni++;nj++;kmp[ni]=nj;
    }
    for(int i=0;i<n;i++){
        if(kmp[i+(2*n+1)]==n){
            cout<<i<<" "<<(b[0]^a[i])<<"\n";
        }
    }
}