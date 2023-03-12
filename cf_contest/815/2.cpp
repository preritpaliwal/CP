#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        int max_val = -1e9, min_val = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            max_val = max(max_val, v[i]);
            min_val = min(min_val, v[i]);
        }

        cout<<2*(max_val-min_val)<<endl;

    }
    return 0;
}

/*

*/