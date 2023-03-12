#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }
    map<int,int> m;
    long long pow = 0;
    for(int i = 0;i<n;i++){
        if(v[i]>0){
            m[v[i]]++;
        }
        else{
            if(m.empty()){
                continue;
            }
            int maxval = (*(m.rbegin())).first;
            pow += 1LL*maxval;
            (*(m.rbegin())).second--;

            if((*(m.rbegin())).second==0){
                m.erase(maxval);
            }
        }
    }
    cout<<pow<<endl;

}

int  main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}