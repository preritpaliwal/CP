#include <bits/stdc++.h>
using namespace std;

long long int count1(int S[], int m, int n){
    if(m==1){
        if(S[0]==n){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    if(n<S[m-1]){
        return 0;
    }
    else if(n==S[m-1]){
        return 1;
    }
    
    int k = 0;
    for(int i = 0;i<m;i++){
        k+= count1(S,i+1,n-S[i]);
        cout<<i<<" "<<k<<" "<<S[m-1]<<" "<<n<<endl;
    }
    return k;
}
long long int count(int S[], int m, int n) {
    sort(S,S+m,greater<int>());
    return count1(S,m,n);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[m];
        for(int i = 0;;);
    }
}