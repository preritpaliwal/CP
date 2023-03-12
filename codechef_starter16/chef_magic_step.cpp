// link to ques : 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fo(i,n) for(int i = 0;i<n;i++)

int getloc(int x,vector<int> &v){
    int l = 0;
    int r = v.size();
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]>x){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(v[l]<=x<v[l+1]){
        return l;
    }
}

bool isprime(int n){
    int z = sqrt(n);
    // cout<<"z = "<<z<<endl;;
    for(int i = 2;i<=z;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int z = sqrt(n);
    for (int i = 5; i <= z; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<"not waiting\n";
    vector<int> v;
    for(int i = 3;i<10e7+1;i++){
        // cout<<i<<endl;
        if(isPrime(i)){
            // cout<<"i =  "<<i<<endl;
            v.pb(i);
        }
    }
    // cout<<"v.size = "<<v.size()<<endl;
    // cout<<"waiting"<<endl;
    int t;
    cin>>t;
    while(t--){
        // cout<<"done preproccesing"<<endl;
        int x,y;
        cin>>x>>y;
        int i_x = getloc(x+2,v);
        int i_y = getloc(y,v);
        // cout<<i_x<<" "<<i_y<<endl;
        cout<<y-x-(i_y-i_x)<<endl;
    }
    return 0;
}