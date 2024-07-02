#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	//完成程序，输出x变量所对应的2进制数。
	int a[100];
	int m=0;
	while(x>1){
		a[m++]=x%2;
		x=x/2;
	}
	a[m]=x;
	for(int i=m;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
