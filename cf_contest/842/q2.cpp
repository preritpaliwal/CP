#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v(n);
        int q=0;
        for(auto &i:v){
            cin>>i.first;
            i.second=q++;
        }
        sort(v.begin(),v.end());
        int ans = 0;    
        bool back = false;
        for(int i = 1;i<n;i++){
            if(back){
                ans++;
                i += (k-1);
                back  =true;
            }
            if(v[i].second-v[i-1].second<0 && !back){
                // cout<<i<<"=i"<<endl;
                ans++;
                i+= (k-1);
                back =  true;
            }
        }
        // cout<<"ans = ";
        cout<<ans<<endl;



    }
    return 0;
}