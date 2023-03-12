// link to ques : https://codeforces.com/problemset/problem/459/A

#include <bits/stdc++.h>
using namespace std;
void print(int x3,int y3,int x4,int y4){
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
}
int main()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        int a = y2-y1;
        print(x1+a,y1,x2+a,y2);
    }
    else if(y1==y2){
        int a = x2-x1;
        print(x1,y1+a,x2,y2+a);
    }
    else if(y1-x1==y2-x2){
        print(x1,y2,x2,y1);
    }
    else if(y1+x1==y2+x2){
        print(x2,y1,x1,y2);
    }
    else{
        cout<<"-1";
    }
    return 0;
}