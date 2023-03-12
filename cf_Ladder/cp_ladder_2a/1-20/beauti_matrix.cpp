// link to ques : https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[5][5];
    int x,y;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin>>a[i][j];
            if(a[i][j]!=0){
                x=j;y=i;
            }
        }
    }

    cout<<abs(x-2)+abs(y-2);

    return 0;
}