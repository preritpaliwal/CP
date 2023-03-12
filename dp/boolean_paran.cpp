// #include <bits/stdc++.h>
// using namespace std;

// int t[201][201][2];
//     void solve(string &S,int l,int r){
//         if(t[l][r][0]!=-1){
//             return;
//         }
//         if(l==r){
//             t[l][r][0] = S[l]=='T';
//             t[l][r][1] = S[l]=='F';
//             return;
//         }
//         // if(l+2==r){
//         //     bool a = S[l]=='T';
//         //     bool b = S[r]=='T';
//         //     if(S[l+1]=='|'){
//         //         if(a|b){
//         //             t[l][r][0] = 1;
//         //             t[l][r][1] = 0;
//         //         }
//         //         else{
//         //             t[l][r][1] = 1;
//         //             t[l][r][0] = 0;
//         //         }
//         //     }
//         //     else if(S[l+1]=='&'){
//         //         if(a&b){
//         //             t[l][r][0] = 1;
//         //             t[l][r][1] = 0;
//         //         }
//         //         else{
//         //             t[l][r][1] = 1;
//         //             t[l][r][0] = 0;
//         //         }
//         //     }
//         //     else if(S[l+1]=='^'){
//         //         if(a^b){
//         //             t[l][r][0] = 1;
//         //             t[l][r][1] = 0;
//         //         }
//         //         else{
//         //             t[l][r][1] = 1;
//         //             t[l][r][0] = 0;
//         //         }
//         //     }
//         //     return;
//         // }
//         int ans1 = 0,ans0 = 0;
//         for(int i = l+1;i<r;i+=2){
//             solve(S,l,i-1);
//             solve(S,i+1,r);
//             if(S[i]=='|'){
//                 ans1 += t[l][i-1][0]*(t[i+1][r][0] + t[i+1][r][1]) + t[l][i-1][1]*t[i+1][r][0];
//                 ans0 += t[l][i-1][1]*t[i+1][r][1];
//             }
//             else if(S[i]=='&'){
//                 ans1 += t[l][i-1][0]*t[i+1][r][0];
//                 ans0 += t[l][i-1][1]*(t[i+1][r][0] + t[i+1][r][1]) + t[l][i-1][0]*t[i+1][r][1];
//             }
//             else if(S[i]=='^'){
//                 ans1 += t[l][i-1][0]*t[i+1][r][1] + t[l][i-1][1]*t[i+1][r][0];  
//                 ans0 += t[l][i-1][1]*t[i+1][r][1] + t[l][i-1][0]*t[i+1][r][0];
//             }
//         }
//         t[l][r][0] = ans1;
//         t[l][r][1] = ans0;
//         return;
//     }
//     int countWays(int N, string S){
//         // code here
//         memset(t,-1,sizeof(t));
//         solve(S,0,N-1);
//         for(int i = 0;i<9;i++){
//             for(int j = 0;j<9;j++){
//                 cout<<t[i][j][0]<<" "<<t[i][j][1]<<" | ";
//             }
//             cout<<endl;
//         }
//         return t[0][N-1][0];
//     }

// int main(){
//     string s = "T|T|T|T|T";
//     // string s2 = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
//     int n = 9;
//     cout<<countWays(n,s)<<endl;
// }

#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];
int parenthesis_count(string s,
					int i,
					int j,
					int isTrue)
{
	// Base Condition
	if (i > j)
		return false;
	if (i == j) {
		if (isTrue == 1)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}
	if (dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];
	int ans = 0;
	for (int k = i + 1
		; k <= j - 1; k = k + 2)
	{
		int leftF, leftT, rightT, rightF;
		if (dp[i][k - 1][1] == -1)
		{
			leftT = parenthesis_count(s, i, k - 1, 1);
		} // Count no. of T in left partition
		else {
			leftT = dp[i][k - 1][1];
		}
		if (dp[k + 1][j][1] == -1)
		{
			rightT = parenthesis_count(s, k + 1, j, 1);
		} // Count no. of T in right partition
		else
		{
			rightT = dp[k + 1][j][1];
		}
		if (dp[i][k - 1][0] == -1)
		{
			// Count no. of F in left partition
			leftF = parenthesis_count(s, i, k - 1, 0);
		}
		else
		{
			leftF = dp[i][k - 1][0];
		}
		if (dp[k + 1][j][0] == -1)
		{
			// Count no. of F in right partition
			rightF = parenthesis_count(s, k + 1, j, 0);
		}
		else
		{
			rightF = dp[k + 1][j][0];
		}

		if (s[k] == '&')
		{
			if (isTrue == 1)
				ans += leftT * rightT;
			else
				ans += leftF * rightF + leftT * rightF
					+ leftF * rightT;
		}
		else if (s[k] == '|')
		{
			if (isTrue == 1)
				ans += leftT * rightT + leftT * rightF
					+ leftF * rightT;
			else
				ans = ans + leftF * rightF;
		}
		else if (s[k] == '^')
		{
			if (isTrue == 1)
				ans = ans + leftF * rightT + leftT * rightF;
			else
				ans = ans + leftT * rightT + leftF * rightF;
		}
		dp[i][j][isTrue] = ans;
	}
	return ans;
}

// Driver Code
int main()
{
	string symbols = "TFFTFFFTTTTFTFFTTF";
	string operators = "|^&|^^^|&^|^^&^|^";
	string s;
	int j = 0;

	for (int i = 0; i < symbols.length(); i++)
	{
		s.push_back(symbols[i]);
		if (j < operators.length())
			s.push_back(operators[j++]);
	}
	
	// We obtain the string T|T&F^T
	int n = s.length();
	
	// There are 4 ways
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
	// (T|((T&F)^T))
	memset(dp, -1, sizeof(dp));
	cout << parenthesis_count(s, 0, n - 1, 1);
	return 0;
}
