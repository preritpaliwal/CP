// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;

// void solve(){
//     int n;cin>>n;
//     if(n<=6){
//         cout<<"NO\n";return;
//     }
//     if(n%3!=0){
//         cout<<"YES\n1 2 "<<n-3<<endl;
//     }
//     else{
//         if(n==9){
//             cout<<"NO\n";
//         }
//         else{
//             if(n%6==0){
//                 cout<<"YES\n1 4 "<<n-5<<endl;
//             }
//             else{
//                 cout<<"YES\n2 5 "<<n-7<<endl;
//             }
//         }
//     }
//     return;
// }

// int main(){
//     int t;cin>>t;
//     while(t--){
//         solve();
//     }
// }

#include <stdio.h>
#include <stdbool.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int s = 0; s < t; s++)
    {
        long n;
        scanf("%ld", &n);
        bool p = false;
        for (int i = 2; i <= n; i++)
        {
            if ((n - 1 - i) % 3 && i % 3 != 0 && (n - i - 1) != 1 && (n - i - 1) != i && (n - 1 - i) > 0)
            {
                p = true;
                printf("YES\n");
                printf("%d %d %ld\n", 1, i, (n - 1 - i));
                break;
            }
        }
        if (!p)
        {
            printf("NO\n");
        }
    }
}