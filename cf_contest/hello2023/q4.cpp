#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n),b(n),c(n);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0;i<n;i++){
            cin>>b[i];
        }

        int m;
        cin>>m;
        multiset<int> x;
        for(int i = 0;i<m;i++){
            int q;
            cin>>q;
            x.insert(q);
        }
        // sort(x.begin(),x.end());

        bool possible = true;

        for(int i = 0;i<n;i++){
            if(a[i]-b[i]<0){
                possible = false;
                break;
            }
            if(a[i]!=b[i]){
                if(x.find(b[i])==x.end()){
                    possible = false;
                    break;
                }
                else{
                    c[i] = b[i];
                }
            }
            else{
                c[i] = -b[i];
            }
        }

        if(!possible){
            cout<<"NO\n";
        }
        else{
            
        }


    }
    return 0;
}