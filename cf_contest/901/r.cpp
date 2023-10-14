#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using ll = long long int;   //typedef ll long long int;
using ii = pair<int,int>;

#define endl '\n' //REMOVE THIS IN INTERACTIVE PROBLEMS
#define F first
#define S second
#define MP make_pair
#define MOD 1000000007
#define MOD1 998244353

ll binexponent(ll a, ll b){
    ll ans =1LL;
    while(b){
        if(b&1){ans*=a; ans%=MOD;}
        b>>=1LL; a*=a; a%=MOD;
    }
    return ans;
}

ll prime[20000001];  
vector<ll>primes;

void SieveOfEratosthenes(ll n) 
{ 
    memset(prime, 0LL, sizeof(prime));
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == 0 ) 
        { 
            primes.push_back(p);
            for (ll i=p*p; i<=sqrt(n); i += p) 
                if(prime[i]==0) prime[i] = p; 
        } 
    } 
   
} 





void solve(int testcase){
    ll a,b;
    cin>>a>>b;

    ll gcdd = __gcd(a,b);

    ll num = gcdd;

    ll cnt =1;

    for(auto x: primes){
        if(x*x>gcdd) break;
        if(num%x == 0){
            cnt++;
        }
        while(num%x == 0){
            num/=x;
        }
    }

    if(num>2){
        cnt++;
    }

    cout<<cnt<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    //
        //code for precomputation to be used across all the testcases.

    //

    int testcases=1;
   
    //cin>>testcases;

    SieveOfEratosthenes(1LL*1000001*1000001);
    cout<<primes.size()<<endl;
    
   for(int i=1; i<=testcases; i++)
    {solve(i);}
    return 0;
}