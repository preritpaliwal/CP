// link to ques : 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    long long q = t;
    while(t--){
        cout<<"Case #"<<q-t<<": ";
        long long n;
        string s;
        cin>>n>>s;
        vector<int> v;
        for(long long i = 0;i<s.size();i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        long long sum = 0;
        sum = v[0]*(v[0]+1)/2;
        for(int i = 1;i<v.size();i++){
            int k = v[i]-v[i-1]-1;
            if(k%2){
                int p = (k+1)/2;
                sum += p*p;
            }
            else{
                int p = k/2;
                sum+= p*(p+1);
            }
        }
        int p = s.size()-1-v[v.size()-1];
        sum+= p*(p+1)/2;
        cout<<sum<<endl;
    }
    return 0;
}