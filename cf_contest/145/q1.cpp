#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    int am = a[0],bm = b[0];
    for(int i = 0;i<n;i++){
        cin>>a[i];
        am = max(am,a[i]);
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
        bm = max(bm,b[i]);
    }
    if(max(am,bm)>max(a[n-1],b[n-1])){

        cout<<"No\n";
        return;
    }
    int minn = min(a[n-1],b[n-1]);
    for(int i = 0;i<n;i++){
        if(minn<min(a[i],b[i])){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}