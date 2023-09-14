#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000007
typedef long long ll;
typedef long double ld;
#define loop(a, i, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define endl '\n'

vector<ll> adjList[200100], revgr[200100];
vector<ll> topo;
ll vis[200100];
void dfs(ll node)
{
    vis[node] = 1;
    for (auto i : adjList[node])
    {
        if (!vis[i])
            dfs(i);
    }
    topo.push_back(node);
}
ll maxo;
void dfs2(ll node, vector<ll> &dp, ll k)
{
    dp[node] += k;
    maxo = max(maxo, dp[node]);
    for (auto i : adjList[node])
    {
        if (dp[i] < dp[node])
            dfs2(i, dp, k);
    }
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    topo.clear();
    vector<ll> hour(n + 1);
    loop(1, i, n + 1) cin >> hour[i];
    loop(0, i, n + 1) adjList[i].clear(), revgr[i].clear();
    ll indeg[n + 1];
    memset(indeg, 0, sizeof(indeg));
    loop(0, i, m)
    {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        indeg[b]++;
        revgr[b].push_back(a);
    }
    loop(1, i, n + 1) vis[i] = 0;
    loop(1, i, n + 1) if (!vis[i]) dfs(i);
    reverse(all(topo));
    vector<ll> dp(n + 1);
    for (auto node : topo)
    {
        ll maxo = 0;
        for (auto i : revgr[node])
            maxo = max(dp[i], maxo);
        dp[node] = k * ((maxo - hour[node] + (k - 1)) / k) + hour[node];
    }

    ll mini = maxi;
    maxo = 0;
    loop(1, i, n + 1) mini = min(mini, dp[i]), maxo = max(maxo, dp[i]);
    ll ans = maxo - mini;
    vector<pair<ll, ll>> harr;
    loop(1, i, n + 1) if (indeg[i] == 0) harr.push_back({hour[i], i});
    sort(all(harr));
    loop(1, i, harr.size())
    {
        mini = dp[harr[i].second];
        dfs2(harr[i - 1].second, dp, k);
        ans = min(ans, maxo - mini);
    }
    cout << ans << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    loop(0, i, t)
        solve();
}