// link to ques : 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for (int i = 0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int k ;
    cin>>k;

// simple copying with extra memory

    // vector<int> rotated;
    // for(int i = n-k;i<nums.size();i++){
    //     rotated.push_back(nums[i]);
    // }
    // for(int i = 0;i<n-k;i++){
    //     rotated.push_back(nums[i]);
    // }
    // cout<<"[";
    // for(int i = 0;i<n;i++){
    //     cout<<rotated[i];
    //     if(i!=n-1){
    //         cout<<',';
    //     }
    // }
    // cout<<"]";

// rotating the vector

    k%=n;
    if(k != 0){
        int z = 0;
        int temp;
        int from = 0;
        int c = nums[from];
        for(int i = 0;i<n;i++){
            temp = nums[(from+k)%n];
            nums[(from+k)%n] = c;
            c = temp;
            from+=k;
            from%=n;
            if(i!=0 && from==z){
                from++;
                z++;
                c = nums[from];
            }
        }
    }

    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}