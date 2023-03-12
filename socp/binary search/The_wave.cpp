// link to ques : https://vjudge.net/contest/444260#problem

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n],b[q];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i = 0;i<q;i++){
        cin>>b[i];
    }
    for(int i = 0;i<q;i++)
    {
        int l = 0;
        int r = n-1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(a[mid]==b[i]){
                l = mid;
                break;
            }
            else if(a[mid]>b[i]){
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        
        if(a[l]==b[i]){
            cout<<"0\n";
        }
        else if(a[l]>b[i]){
            cout<<"POSITIVE\n";
        }
        else if(a[r]){
            cout<<"POSITIVE\n";
        }
    }
    return 0;
}