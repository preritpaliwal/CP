#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int
#define fo(i, a, n) for (ll i = a; i < n; i++)
#define fo0(i, n) for (ll i = 0; i < n; i++)
#define fom(i, a, n) for (ll i = n; i >= a; i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define qll queue<ll>
#define qpll queue<pair<ll, ll>>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
void print(vll v)
{
    fo0(i, v.size()) { cout << v[i] << " "; }
    cout << endl;
}

void check(ll n, ll &sum, ll &prod)
{
    vll d;
    ll temp = n, no_d = 0;
    while (temp != 0)
    {
        d.push_back(temp % 10);
        sum += d[no_d];
        prod *= d[no_d++];
        temp /= 10;
    }
}

ll getProd(ll n)
{
    ll tmp = n, prod = 1;
    while (tmp != 0)
    {
        prod *= (tmp % 10);
        tmp /= 10;
    }
    return prod;
}

void modify(ll &sum, ll &prod, ll x)
{
    if (x % 10 == 0)
    {
        prod = 0;
        sum = sum - 8;
        ll k = -1;
        ll y = x - 1;
        while (true)
        {
            x /= 10;
            y /= 10;
            // cout<<"X,y = "<<x<<" "<<y<<endl;
            if (x % 10 == y % 10)
            {
                sum -= 9 * k;
                break;
            }
            k++;
        }
    }
    else
    {
        ll a = x % 10;
        ll b = a - 1;
        // cout<<" a,b "<<a<<","<<b<<endl;
        if (b == 0)
        {
            prod = getProd(x);
        }
        else
        {
            prod = (prod / (b)) * (a);
        }
        sum = sum - b + a;
    }
    // cout<<"sum,prod = "<<sum<<" "<<prod<<endl;
}

int main()
{
    fast int t;
    cin >> t;
    fo0(T, t)
    {
        cout << "Case #" << T + 1 << ": ";
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        ll sum = 0, prod = 1;
        check(a, sum, prod);
        if (prod % sum == 0)
        {
            ans++;
        }
        fo(i, a + 1, b + 1)
        {
            // cout<<i<<endl;
            modify(sum, prod, i);
            if (prod % sum == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}