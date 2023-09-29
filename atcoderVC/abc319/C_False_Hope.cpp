#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[9];for(int i=0;i<9;i++)cin>>a[i];
    vector<vector<int>> check{{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int p[9];
    for(int i=0;i<9;i++)p[i]=i;
    int nops=0;
    int ops=0;
    do{
        bool dis=false;
        ops++;
        for(auto c:check){
            if(a[c[0]]==a[c[1]] && p[c[0]]<p[c[2]] && p[c[1]]<p[c[2]])dis=true;
            if(a[c[2]]==a[c[1]] && p[c[2]]<p[c[0]] && p[c[1]]<p[c[0]])dis=true;
            if(a[c[0]]==a[c[2]] && p[c[0]]<p[c[1]] && p[c[2]]<p[c[1]])dis=true;
        }
        if(!dis)nops++;
    }while(next_permutation(p,p+9));
    cout<<setprecision(15)<<(double)nops/ops<<endl;
}