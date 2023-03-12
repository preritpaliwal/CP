// link to ques : https://codeforces.com/contest/231/problem/C

#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> v,int l,int r,int a,int k){
    int req = a*(r-l+1) - (v[r]-v[l-1]);
    if(k>=req){
        return req;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n,0);
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int max_i = -1;
        int max = 0;
        vector<int> ps(n,0);
        ps[0] = v[0];
        for(int i = 1;i<n;i++){
            ps[i]=ps[i-1]+v[i];
        }
        int l_p = 0;
        for(int i = 0;i<n;i++){
            int l = l_p;
            int r = i-1;
            int k_cur = k;
            while(l<=r){
                int mid = (l+r)/2;
                int state = possible(ps,mid,r,v[i],k_cur);
                if(state!=-1){
                    r = mid-1;
                    k_cur -= state;
                }
                else{
                    l = mid;
                }
                if(r-l==1){
                    if(v[i]-v[r]<=k){
                        l=r;
                        break;
                    }
                }
            }
            if(i-l+1>max){
                max = i-l+1;
                max_i = i;
            }
            l_p = l;
        }
        cout<<max<<" "<<v[max_i]<<endl;
    }
    return 0;
}