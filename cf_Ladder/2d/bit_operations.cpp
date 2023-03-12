#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i = 0;i<pow(2,n);i++){
        int in;
        cin>>in;
        v.push_back(in);
    }
    vector<vector<int>> itrs;
    itrs.push_back(v);
    for(int i = 1;i<=n;i++){
        vector<int> itr;
        vector<int> &prev = itrs.back();
        if(i%2==1){
            for(int j  =0;j<prev.size();j+=2){
                itr.push_back(prev[j]|prev[j+1]);
            }
        }else{
            for(int j = 0;j<prev.size();j+=2){
                itr.push_back(prev[j]^prev[j+1]);
            }
        }
        itrs.push_back(itr);
    }

    while(m--){
        int p,b;
        cin>>p>>b;
        p--;
        itrs[0][p] = b;
        p /= 2;
        for(int i = 1;i<=n;i++){
            if(i%2==1){
                itrs[i][p] = itrs[i-1][2*p] | itrs[i-1][2*p+1];
            }
            else{
                itrs[i][p] = itrs[i-1][2*p] ^ itrs[i-1][2*p+1];
            }
            p /=2;
        }
        cout<<itrs[n][0]<<endl;
    }

}