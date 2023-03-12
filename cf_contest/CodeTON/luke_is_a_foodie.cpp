#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
        int curmin = v[0],curmax = v[0],ans = 0;
        for(int i =1;i<n;i++){
            curmin = min(curmin,v[i]);
            curmax = max(curmax,v[i]);
            if(curmax-curmin>2*x){
                ans++;
                curmax = v[i];
                curmin = v[i];
            }
        }
        cout<<ans<<endl;
    }
}