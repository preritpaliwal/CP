// link to ques : https://codeforces.com/problemset/problem/490/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    vector<int> v1,v2,v3;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a;
        if(a==1){
            v1.push_back(i+1);
        }
        else if(a==2){
            v2.push_back(i+1);
        }
        else{
            v3.push_back(i+1);
        }
    }
    int z = min(v1.size(),min(v2.size(),v3.size()));
    cout<<z<<endl;
    for(int i = 0;i<z;i++){
        cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<endl;
    }
    return 0;
}