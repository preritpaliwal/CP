// link to ques : https://www.codechef.com/SNCKQL21/problems/MAXDISTKT

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        int k;
        for(int i  = 0;i<n;i++){
            cin>>k;
            v.push_back(make_pair(k,i));
        }
        sort(v.begin(),v.end());

        vector<int> r(n,0);
        int rem = 0;
        for(int i =0;i<n;i++){
            if(rem<v[i].first){
                r[i] = rem;
                rem++;
            }
        }
        int a[n];
        for(int i = 0;i<n;i++){
            a[v[i].second] = r[i] + v[i].first;
        }
        
        for(int i = 0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}