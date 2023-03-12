// link to ques : https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

int n1=nums1.size(),n2=nums2.size();
// ------------using another vector------------------------

    // vector<int> num;
    // 
    // int i =0,j=0;
    // while(i<n1 && j<n2){
    //     if(nums1[i]<=nums2[j]){
    //         num[k]=nums1[i];
    //         i++;
    //         k++;
    //     }
    //     else{
    //         num[k]=nums2[j];
    //         j++;
    //         k++;
    //     }
    // }
    // while(i<n1){
    //     num[k]=nums1[i];
    //     i++;
    //     k++;
    // }
    // while(j<n2){
    //     num[k]=nums2[j];
    //     j++;
    //     k++;
    // }
    // cout<<"srdcfvgbh"<<endl;
    // if(k%2==1){
    //     return num[k/2];
    // }
    // else{
    //     return (num[k/2]+num[(k/2)-1])/2;
    // }

    // divide and conquer
    
    int x = ((n1+n2)/2)-1;
    int l = 0;
    int r = n1-1;
    int m;
    while(l!=r){
        cout<<"inside while"<<endl;
        m = (l+r)/2;
        if(nums1[m]==nums2[x-m]){
            break;
        }
        else if(nums1[m]<nums2[x-m]){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    if((n1+n2)%2==1){
        return max(nums1[m],nums2[x-m]);
    }
    else{
        return (max(nums1[m],nums2[x-m]) + min(nums1[m+1],nums2[x-m+1]))/2;
    }

    NOT working.... please think again.

}

int main()
{
    vector<int> v{1,3};
    vector<int> q{2};
    cout<<findMedianSortedArrays(v,q);
    return 0;
}