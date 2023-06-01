#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int maxl = n;
    int minr = -1;
    for(int i = 0;i<n;i++){
        cin>>b[i];
        if(b[i]!=a[i]){
            if(maxl == n){
                maxl = i;
            }
            minr = i;
        }
    }
    for(int i = maxl;i>=0;i--){
        maxl = i;
        if(i!=0 && b[i]<b[i-1]){
            break;
        }
    }

    for(int i = minr;i<n;i++){
        minr = i;
        if(i!=n-1 && b[i]>b[i+1]){
            break;
        }
    }

    cout<<maxl+1<<" "<<1+minr<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}