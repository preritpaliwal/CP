// link to ques : https://leetcode.com/problems/max-chunks-to-make-sorted/

#include <bits/stdc++.h>
using namespace std;

void get_min(vector<int> a,int start,int *index){
    int min = a[start];
    *index = start;
    for(int i = 1+start;i<a.size();i++){
        if(a[i]<min){
            min=a[i];
            *index = i;
        }
    }
}

int get_max(vector<int> a,int start,int index){
    int max = a[start];
    for(int i = 0;i<index;i++){
        if(max<a[i]){
            max = a[i];
        }
    }
    return max;
}

int check_chunk(vector<int> a,int l,int r){
    int max = get_max(a,l,r);
    int extend = -1;
    for(int i = r+1;i<a.size();i++){
        if(max>a[i]){
            extend = i;
        }
    }
    return extend;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int start = 0;
    int index = -1;
    int k = 0;

    while(start<arr.size()){
        get_min(arr,start,&index);
        k++;
        int extention = check_chunk(arr,start,index);
        // cout<<"extention : "<<extention<<endl;
        while(extention!=-1){
            // cout<<"index : "<<index<<"->"<<extention<<endl;
            index = extention;
            extention = check_chunk(arr,start,index);
        }
        start = index+1;
        // cout<<"start : "<<start<<endl<<"index : "<<index<<endl;
    }
    cout<<k;
    return 0;
}