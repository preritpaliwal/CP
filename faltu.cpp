#include <bits/stdc++.h>
using namespace std;

#define ll long long int



int main() {
    int t=1;cin >> t;
    while (t--) {
        int n, m;cin >> n >> m;

        vector<vector<int>> grid, psum;
        grid.resize(n, vector<int>(m, 0));
        psum.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int fans = 0;
        if (m >= n) {
            for (int i = 0; i < n;i++) {
                psum[i][0] = grid[i][0];
            }
            for (int i = 0; i < n;i++) {
                for (int j = 1; j < m; j++) {

                    if (grid[i][j] == 1) {
                        psum[i][j] = psum[i][j - 1] + 1;
                    }
                    else psum[i][j] = 0;
                }
            }

            for (int i = 0; i < n;i++) {
                for (int j = 0; j < m; j++) {
                    int mnlen = psum[i][j];
                    fans = max(fans, mnlen);
                    for (int k = i - 1;k >= 0;k--) {
                        mnlen = min(psum[k][j], mnlen);
                        fans = max(fans, mnlen * (i - k + 1));
                    }

                }
            }

        }

        else {
            for (int i = 0; i < m;i++) {
                psum[0][i] = grid[0][i];
            }
            for (int i = 0; i < m;i++) {
                for (int j = 1; j < n; j++) {

                    if (grid[j][i] == 1) {
                        psum[j][i] = psum[j - 1][i] + 1;
                    }
                    else psum[j][i] = 0;
                }
            }

            for (int i = 0; i < m;i++) {
                for (int j = 0; j < n; j++) {
                    int mnlen = psum[j][i];
                        fans = max(fans, mnlen);
                    for (int k = i - 1;k >= 0;k--) {
                        mnlen = min(psum[j][k], mnlen);
                        fans = max(fans, mnlen * (i - k + 1));
                    }

                }
            }

        }

        cout<<fans<<'\n';
    }
}
