#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int ones = 0;
    int z = 0;
    bool possible = true;
    int n = A.size();
    for(int i = 0;i< (int)n;i++){
        if(A[i]){
            ones++;
            z = 0;
        }
        else{
            z++;
        }
        if(z==2*B-1){
            possible = false;
            break;
        }
    }
    if(possible){
        // int l = 0,r = ones,mid;
        // while(l<=r){
        //     mid = (l+r)/2;
        //     int last = 0;
        //     for(int i = 0;i<mid;i++){
        //         for(int j = last + B-1;j>=last;j--){
        //             if(A[j]){
        //                 last = j + B-1;
        //                 break;
        //             }
        //         }
        //     }
        // }

        int last = -1;
        int step = 0;
        for(int i = B-1;i>-1;i--){
            cout<<i<<" "<<last<<" "<<n<<endl;
            if(last+1 >= (int)n){
                cout<<"Here"<<last<<" "<<n<<endl;
                break;
            }
            if(i>= (int) n){
                i = n-1;
            }
            if(A[i]){
                last = i + B-1;
                i = last + B;
                step ++;
                // cout<<"l,i,s: "<<last<<" "<<i<<" "<<step<<endl;
            }
        }
        return step;
    }
    else{
        return -1;
    }
}


int main(){
    vector<int> A{1,1,1,1};
    cout<<"ans : "<<solve(A,3)<<endl;;
    return 0;
}