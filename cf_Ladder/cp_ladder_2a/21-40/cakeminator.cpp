// link to ques : https://codeforces.com/problemset/problem/330/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    char c;
    cin>>n>>m;
    set<int> vi,vj;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>c;
            if(c=='.'){
                continue;
            }
            vi.insert(i);
            vj.insert(j);
        }
    }
    cout<<(vj.size())*(n-vi.size()) + n*(m-vj.size());
    return 0;
}