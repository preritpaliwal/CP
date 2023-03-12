#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> v(m);
        for(auto &a:v){
            cin>>a;
        }
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        for(int i = 1;i<m;i++){
            pq.push(v[i]-v[i-1]-1);
        }
        pq.push(n-v[m-1] + v[0]-1);
        int ans = 0;
        int days = 0;
        while(!pq.empty()){
            // cout<<ans<<endl;
            int k = pq.top();pq.pop();
            if(k-2*days<=0){
                break;
            }
            if(k-2*days==1){
                ans++;
                break;
            }
            else{
                ans+= (k-2*days-1);
            }
            days+=2;
        }
        cout<<n-ans<<endl;
    }
}