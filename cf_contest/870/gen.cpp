#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll ra(ll a,ll b){
    return rand()%(b-a+1) +a;
}

void solve(){
    int m=ra(1,500),n=ra(1,5000);
    cout<<m<<" "<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<ra(1,1e9)<<" ";
    }
    cout<<"\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ra(1,n)<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    solve();
    return 0;
}