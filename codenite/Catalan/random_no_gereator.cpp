#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int t;
	t = 100;
	cout<<t<<endl;
	for(int i = 0;i<t;i++){
		cout<<rand(50,200000)<<endl;
	}
	return 0;
}