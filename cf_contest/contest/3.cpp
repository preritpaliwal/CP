#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        vector<int> premax(n);
        for(auto &v:a){
            cin>>v;
        }
        vector<int> ans(n,0);
        int i_curMax ;
        if(a[1]<a[0]){
            i_curMax = 0;
        }
        else{
            i_curMax = 1;
        }
        ans[i_curMax]++;
        premax[0] = i_curMax;
        premax[1] = i_curMax;
        for(int i = 2;i<n;i++){
            if(a[i_curMax]<a[i]){
                i_curMax = i;
            }
            ans[i_curMax]++;
            premax[i] = i_curMax;
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            if(r>=i_curMax){
                if(l==i_curMax){
                    cout<<ans[i_curMax]+r-n+1<<"\n";
                }
                else{
                    cout<<ans[l]<<"\n";
                }
            }
            else{
                if(premax[l]==l){
                    cout<<r-max(premax[l],1)+1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
        }
    }
    return 0;
}