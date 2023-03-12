// link  to ques : https://www.codechef.com/problems/CHEFPAT

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    vector<pair<int,int>> v;
	    int n;
	    cin>>n;
	    for(int i=0; i<n;i++)
	    {
	        int k;
	        cin>>k;
	        v.push_back(make_pair(k,i));
	    }
	    sort(v.begin(),v.end());
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        a[v[i].second] = i+1;
	    }
	    for(int i = 0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
