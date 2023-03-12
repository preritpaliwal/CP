// link to ques : https://www.credit-suisse.com/pwp/hr/en/codingchallenge/?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9.eyJleHAiOjE2MzQ2NjA5OTAsImlhdCI6MTYzMzQ1MTM5MCwianRpIjoiNTFiNjQ0MjQtNzNlMS00MzM4LWIyYjAtOTUwMzlmMTllMGJkIiwiaXNzIjoiZ2NjLWFwaSIsImF1ZCI6ImdjYy1hcHAiLCJzdWIiOiJwcmVyaXRwYWxpd2FsIiwicm9sIjpbIlVTRVIiXSwibmFtZSI6IlByZXJpdCAgUGFsaXdhbCIsInByZWZlcnJlZF91c2VybmFtZSI6InByZXJpdHBhbGl3YWwiLCJlbWFpbCI6InByZXJpdC5wYWxpd2FsMDA3QGdtYWlsLmNvbSJ9.lggWYRkqIAGLIIM_iocK4ziFdo9Je7ZTT0W4yvicbbLvv7bdmf9NZQQ2y8B2_zFc9AbXVi1mGAXhjNjHKDIVvg#/questions/4

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i = 0;i<n;i++){
        cin>>p[i];
    }
    int max_profit = 0;
    int min_price = p[0];
    for(int i = 1;i<n;i++){
        if(p[i]<min_price){
            min_price = p[i];
        }
        else{
            max_profit = max(max_profit,p[i]-min_price);
        }
    }
    cout<<max_profit;
    
    return 0;
}