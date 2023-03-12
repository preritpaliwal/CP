// link to ques : https://codeforces.com/problemset/problem/1476/A

#include <bits/stdc++.h>
using namespace std;
int correct(double a)
{
    int b = a;
    if (a==b)
    {
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double n,k;
        cin>>n>>k;
        if(n==k)
        {
            cout<<1<<endl;;
        }
        else if(n>k)
        {
            cout<<1+correct((n/k))<<endl;
        }
        else
        {
            cout<<(int)(k/n)+correct((k/n))<<"\n";
        }

        //********************************************************************************* 
        //binary search
        long long n,k;
        cin>>n>>k;
        if(n%k==0)
        {
            cout<<1<<endl;
        }
        else
        {
            long long l = 1;
            long long r = k;
            long long z;
            z=(n/k)+1;
            while(r-l>1)
            {
                long long mid = (l+r)/2;
                // cout<<mid<<"   ";
                if(z*k<=mid*n)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            cout<<r<<endl;
        }
    }
    return 0;
}