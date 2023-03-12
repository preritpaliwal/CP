// link to ques : 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t --){
        int n,k;
        cin>>n>>k;
        vector<int> v(n,0);
        int k_cur = 0;
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }                         


        int b=0,e=-1;
        int ans = 0;
        set<int> s;
        while(b<n){
            // cout<<b<<","<<e<<endl;           
            e++;
            if(e==n){
                // cout<<"Out of bounds\n";
                e = b;
                b++;
                s.clear();
                k_cur=0;
                continue;
            }
            if(s.find(v[e])==s.end()){
                // cout<<"New value\n";
                k_cur++;
                s.insert(v[e]);
            }
            if(k_cur<=k){
                // cout<<"increasing ANS "<<ans+1<<"\n";
                ans++;
            }
            else{
                // cout<<"reseting\n";
                e = b;
                b++;
                s.clear();
                k_cur=0;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}