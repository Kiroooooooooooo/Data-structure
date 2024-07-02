#include <iostream>
using namespace std;

int main()
{
	int x;	//代表一个十进制数。
	int y;	//代表进制
	cin >> x;
	cin >> y;
	//完成程序，输出x变量所对应的y进制数。
    int a[100];
    int m=0;
    while(x>1){
    	a[m++]=x%y;
    	x=x/y;
	}
	a[m]=x;
	for(int i=m;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
