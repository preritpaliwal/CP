#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using ll = long long;

struct no
{
    ll len;
    ll idx;
    no()
    {
        len = 0;
        idx = -1;
    }
};

ll n, d;
vector<ll> v;
vector<struct no> t;
vector<no> dp;
map<ll, ll> mp;

struct no merge(struct no n1, struct no n2)
{
    struct no tmp;
    tmp.len = max(n1.len, n2.len);
    tmp.idx = ((n1.len == tmp.len) ? n1.idx : n2.idx);
    return tmp;
}

void update(ll id, ll l, ll r, ll pos, ll val, ll idx)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        t[id].len = val;
        t[id].idx = idx;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val, idx);
    update(id << 1 | 1, mid + 1, r, pos, val, idx);
    t[id] = merge(t[id << 1], t[id << 1 | 1]);
}

struct no query(ll id, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return no();
    if (ql <= l && r <= qr)
        return t[id];
    int mid = (l + r) >> 1;
    return merge(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void debug()
{
    for (int i = 1; i <= 2 * n; i++)
    {
        cerr << t[i].len << " ";
    }
    cerr << endl;
    for (int i = 1; i <= 2 * n; i++)
    {
        cerr << t[i].idx << " ";
    }
    cerr << endl;
}

int main()
{
    cin >> n >> d;
    v.resize(n + 1);
    t.resize(4 * n);
    dp.resize(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        mp[v[i]] = 0;
    }
    ll cnt = 1;
    for (auto &it : mp)
    {
        it.second = cnt++;
    }
    for (ll i = 1; i <= n; i++)
    {
        auto it = mp.lower_bound(v[i] + d);
        struct no curMax;
        if (it != mp.end())
        {
            curMax = query(1, 1, n, it->second, n);
        }
        auto it2 = mp.upper_bound(v[i] - d);
        if (it2 != mp.begin())
        {
            it2--;
            curMax = merge(curMax, query(1, 1, n, 0, it2->second));
        }
        dp[i].len = curMax.len + 1;
        dp[i].idx = curMax.idx;
        update(1, 1, n, mp[v[i]], dp[i].len, i);
    }
    ll maxi = 0;
    for (int i = 1; i <= n; i++)
        maxi = ((dp[maxi].len >= dp[i].len) ? maxi : i);
    cout << dp[maxi].len << endl;
    vector<ll> ans;
    while (maxi > 0)
    {
        ans.push_back(maxi);
        maxi = dp[maxi].idx;
    }
    for (auto it = ans.rbegin(); it < ans.rend(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}