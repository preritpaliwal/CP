#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first 
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i,N) for(i=0;i<(N);++i)
#define FORe(i,N) for(i=1;i<=(N);++i)
#define FORr(i,a,b) for(i=(a);i<(b);++i)
#define FORrev(i,N) for(i=(N);i>=0;--i)
#define F0R(i,N) for(int i=0;i<(N);++i)
#define F0Re(i,N) for(int i=1;i<=(N);++i)
#define F0Rr(i,a,b) for(ll i=(a);i<(b);++i)
#define F0Rrev(i,N) for(int i=(N);i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define dbgLine cerr<<" LINE : "<<__LINE__<<"\n"
#define ldd long double

using namespace std;

const int Alp = 26;
const int __PRECISION = 9;
const int inf = 1e9 + 8;

const ldd PI = acos(-1);
const ldd EPS = 1e-7;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 5;
const ll ROOTN = 320;
const ll LOGN = 18;
const ll INF = 1e18 + 1022;

ll ans[MAXN];
ll fxp(ll a, ll n){
	if(!n) return 1;
	if(n & 1) return a * fxp(a, n ^ 1) % MOD;
	return fxp(a * a % MOD, n >> 1);
}
#define inv(x) fxp((x), MOD - 2)

inline void test_case(){
	int N;
	cin >> N;
	cout << ans[N] << '\n';
}

signed main(){

	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/

	ans[0] = 1;
	F0Re(i, MAXN - 1){
		ans[i] = ans[i - 1] * (4LL * i - 2) % MOD * inv(i + 1) % MOD;
	}


	int test_case_number;
	cin>>test_case_number;
	while(test_case_number--)
		test_case();
	
	return 0;
}