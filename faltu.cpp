#include <iostream>
using namespace std;

int main()
{
  int a,b;
  char op;
  cout<<" enter operator: ";
  cin>>op;

  cout<<"enter 2 nos: ";
  cin>>a>>b;
  if(op=='+'){
    cout<<a+b;
  }
  else if(op == '-'){
    cout<<a-b;
  }
  else{
    cout<<"wrong operator";
  }
  cout<<"you entered this : "<<op;
	return 0;
}