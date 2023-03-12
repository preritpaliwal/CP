#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int _ = 0;_<t;_++){
        cout<<"Case #"<<_+1<<": ";
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
        }
        if(m>=n){
            int ans = 0;
            for(auto i:a){
                ans += i;
            }
            cout<<fixed<<setprecision(1)<<ans<<endl;
        }
        else{
            double ans = 0;
            sort(a.begin(),a.end());
            for(int i = 0;i<m-1;i++){
                ans += a[n-1-i];
            }
            if((n-m+1)%2 == 0){
                ans += (a[(n-m+1)/2] + a[(n-m+1)/2 -1]);
            }
            else{
                // cout<<a[(n-m)/2];
                ans += a[(n-m)/2];
            }
            cout<<fixed<<setprecision(1)<<ans<<endl;   
        }
    }
}