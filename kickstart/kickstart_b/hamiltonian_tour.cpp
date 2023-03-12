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
void print(vector<char> &v)
{
    fo0(i, v.size()) { cout << v[i]; }
}
int v[400][400];
int r, c;
vector<char> path;
bool check(int x, int y)
{
    if (x < 0 || x >= 2 * c)
    {
        return false;
    }
    if (y < 0 || y >= 2 * r)
    {
        return false;
    }
    if (v[y][x] == 2)
    {
        return false;
    }
    return true;
}
void dfs(int x, int y)
{
    v[y][x] = 2;
    // cout<<"\nstart----------------------------\n";
    // for (int i = 0; i < 2 * r; i++)
    // {
    //     for (int j = 0; j < 2 * c; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout<<"---------------------------\n";
    // cout<<y<<x<<endl;
    // if (x == 1 && y == 0)
    // {
    //     // cout<<'W'<<endl;
    //     path.push_back('W');
    //     return;
    // }
    // cont++;
    // if(cont>999){
    //     return;
    // }
    if (check(x - 1, y))
    {
        // cout<<'W';
        path.push_back('W');
        dfs(x - 1, y);
        return;
    }
    if (check(x, y + 1))
    {
        // cout<<'S';
        path.push_back('S');
        dfs(x, y + 1);
        return;
    }
    if (check(x + 1, y))
    {
        // cout<<'E';
        path.push_back('E');
        dfs(x + 1, y);
        return;
    }
    if (check(x, y - 1))
    {
        // cout<<'N';
        path.push_back('N');
        dfs(x, y - 1);
        return;
    }
}
int main()
{
    fast int _;
    cin >> _;
    for (int t = 0; t < _; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        // int r,c;
        cin >> r >> c;
        char ch;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> ch;
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        v[2 * i + x][2 * j + y] = (ch == '*' ? 1 : 2);
                    }
                }
            }
        }
        // for (int i = 0; i < 2 * r; i++)
        // {
        //     for (int j = 0; j < 2 * c; j++)
        //     {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        dfs(0, 0);
        bool possible = true;
        for (int i = 0; i < 2 * r; i++)
        {
            for (int j = 0; j < 2 * c; j++)
            {
                // cout<<v[i][j]<<" ";
                if (v[i][j] != 2)
                {
                    possible = false;
                    break;
                }
            }
            // cout<<endl;
        }
        if (possible)
        {
            print(path);
            cout<<'W'<<endl;
            path.clear();
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
            path.clear();
        }
    }
    return 0;
}