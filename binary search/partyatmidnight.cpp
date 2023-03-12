// link to ques : https://codeforces.com/problemset/problem/750/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

// ***************************************************
// logic using quadratic eqn (fastest...atleast here)

    // int z = 2*(240 - k)/5;
    // int t = (sqrt(1+4*z)-1)/2;
    // if(t>=n)
    // {
    //     cout<<n;
    // }
    // else
    // {
    //     cout<<t;
    // }

//*****************************************************

// linear search
    // int i;
    // for( i = 0;i<=n;i++)
    // {
    //     if((240-k-(5*(i*i + i)/2))<0)
    //     {
    //         break;
    //     }
    // }
    // cout<<i-1;

//*****************************************************
//binary search
    int r = n;
    int l = 0;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        
        if(240-k-(5*(mid*mid + mid)/2)>=0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(240-k-(5*(r*r + r)/2)>=0)
    {
        cout<<r;
    }
    else
    {
        cout<<l;
    }
    return 0;
}