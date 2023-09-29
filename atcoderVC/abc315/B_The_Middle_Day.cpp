#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int m,tot=1;cin>>m;vector<int> d(m);for(int &i:d){cin>>i;tot+=i;}
    int find=tot/2;
    for(int i=0;i<m;i++){
        if(find>d[i]){find-=d[i];continue;}
        cout<<i+1<<" "<<find<<endl;
        break;
    }
    return 0;
}