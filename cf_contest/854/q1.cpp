#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        // cout<<"n,m = "<<n<<" "<<m<<endl;
        set<int> s;
        vector<int> v(n,-1);
        for(int i = 0;i<m;i++){
            int a;
            cin>>a;
            if(s.find(a)==s.end()){
                s.insert(a);
                if(s.size()<=n){
                    v[n-s.size()] = i+1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}