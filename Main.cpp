#include <iostream>
using namespace std;

//����������˳��������
#include "SeqList.h"
#include "SeqList.cpp"

//���������ڳ�����ʹ��˳���
int main()
{
	//����һ��˳���
    SeqList <int> seq(5);	

	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;
	if( seq.isFull() )cout << "˳�������" << endl;
	else cout << "˳���δ��" << endl;

	for(int i = 0; i < 5; i ++)
	{
		seq.insert(i , i);
	}
	cout << "˳���ǰ�������£�" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;
	if( seq.isFull() )cout << "˳�������" << endl;
	else cout << "˳���δ��" << endl;
	int x;
	seq.remove(1 , x);
	cout << "˳���ǰ�������£�" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;
	if( seq.isFull() )cout << "˳�������" << endl;
	else cout << "˳���δ��" << endl;
	cout << "˳����ڵ�ǰԪ�ظ�����" << seq.length() << endl;
	cout << "˳����������Ԫ�ظ�����" << seq.size() << endl;
	x = 3;
	cout << "����" << x << "��˳����е�����λ��Ϊ��" << seq.search(x) << endl;
	seq.getData(1 , x);
	cout << "˳�����1������λ�õ�����ֵΪ��" << x << endl;
	x = 100;
	seq.setData(2 , x);
	cout << "˳���ǰ�������£�" << endl;
	seq.output();
	seq.makeEmpty();
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;
}

