#include <iostream>
using namespace std;

int main()
{
	int x;	//����һ��ʮ��������
	int y;	//�������
	cin >> x;
	cin >> y;
	//��ɳ������x��������Ӧ��y��������
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
