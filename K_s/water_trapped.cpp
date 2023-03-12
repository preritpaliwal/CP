// link to ques : https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

int water_btw_peeks(int l,int r,vector<int> h){
    int hi = min(h[l],h[r]);
    int water = 0;
    for(int i = l+1;i<r;i++){
        if(h[i]>=hi){
            continue;
        }
        water += hi- h[i];
    }
    return water;
}

int get_water(vector<int> peek,vector<int> h){
    int water_total = 0;
    for(int i = 0;i<peek.size()-1;i++){
        water_total += water_btw_peeks(peek[i],peek[i+1],h);
    }
    return water_total;
}

void swap(int *a,int *b){
    int k = *a;
    *a = *b;
    *b = k;
}

void get_max(vector<int> v,vector<int> h,int *a,int *b){
    int max = 0;
    for(int i = 0;i<v.size();i++){
        if(max<h[v[i]]){
            max = h[v[i]];
            *a = i;
        }
    }
    // cout<<"max = "<<max<<"*a = "<<*a<<endl;
    int s_max = 0;
    for(int i = 0;i<v.size();i++){
        if(i==*a){
            continue;
        }
        if(s_max<h[v[i]]){
            s_max = h[v[i]];
            // cout<<"smax = "<<s_max<<endl;
            *b = i;
        }
    }
    if(*a>*b){
        swap(a,b);
    }
}

vector<int> max_peeks(vector<int> v,vector<int> h){
    if(v.size()==0){
        return v;
    }
    else if(v.size()==1){
        return v;
    }

    int l,r;
    get_max(v,h,&l,&r);
    // cout<<"max are at "<<v[l]<<","<<v[r]<<endl;
    vector<int> left;
    vector<int> right;
    for(int i = 0;i<v.size();i++){
        if(i<l){
            left.push_back(v[i]);
        }
        else if(i>r){
            right.push_back(v[i]);
        }
    }
    vector<int> max_left = max_peeks(left,h);
    vector<int> max_right = max_peeks(right,h);

    vector<int> max_peek;
    int j=0,k=0;
    for(int i = 0;i<max_left.size()+max_right.size()+2;i++){
        if(i<max_left.size()){
            max_peek.push_back(max_left[j]);
            j++;
        }
        else if(i==max_left.size()){
            max_peek.push_back(v[l]);
        }
        else if(i==max_left.size()+1){
            max_peek.push_back(v[r]);
        }
        else{
            max_peek.push_back(max_right[k]);
            k++;
        }
    }
    return max_peek;
}

void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    vector<int> height;
    for (int i = 0;i<n;i++){
        int a;
        cin>>a;
        height.push_back(a);
    }

    vector<int> peeks;
    for(int i = 0;i<height.size();i++){
        if(i==0){
            if(height[i]>height[i+1]){
                peeks.push_back(i);
            }
        }
        else if(i==height.size()-1){
            if(height[i]>height[i-1]){
                peeks.push_back(i);
            }
        }
        else if(height[i]>height[i-1] && height[i]>height[i+1]){
            peeks.push_back(i);
        }
    }
    vector<int> max_peek = max_peeks(peeks,height);
    // print(max_peek);
    cout<<get_water(max_peek,height);
    return 0;
}

/*

12
0 1 0 2 1 0 1 3 2 1 2 1
6
4 2 0 3 2 5

*/