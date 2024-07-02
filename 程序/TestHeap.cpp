#include <iostream>
using namespace std;

template <class T>
class MinHeap {	// ��С���ඨ��
private:
	T *heap;				// ��С��Ԫ�ش洢����
	int currentSize;		// ��С�ѵ�ǰԪ�ظ���
	int maxHeapSize;		// ��С���������

	void siftDown (int start, int m);	// �����㷨���� start ��ʼ���µ����� m
	void siftUp (int start);			// �����㷨���� start ��ʼ���ϵ���

public:
	MinHeap(int sz = 10);		// ���캯��������Ϊ sz

	MinHeap(T arr[ ], int n);			// ���캯���������� arr[ ] ���Ԫ�ش�����

	~MinHeap( ) { delete [ ]heap; }		// ��������

	bool Insert (const T d);			// ����
	bool Remove (T& d);					// ɾ��

	bool IsEmpty ( )const;				// �жѿշ�
	bool IsFull ( ) const;				// �ж�����
	void MakeEmpty ( );					// �ÿն�

	void Display( )const {
		for(int i = 0; i < currentSize; i++)
			cout << heap[i] << "  ";
		cout << endl;
	}

};

template <class T>
void MinHeap<T>::siftDown (int start, int m ) {
// ˽�к������ӽ�� start ��ʼ�� m Ϊֹ���������±Ƚϣ�
// ����ǰstart��ָ�Ľڵ�ŵ���ȷ��λ�á�
	
}

template <class T>
void MinHeap<T>::siftUp(int start) {
// ˽�к������ӽ�� start ��ʼ����� 0 Ϊֹ���������ϱȽϣ�
// ����ǰstart��ָ�Ľڵ�ŵ���ȷ��λ�á�

}

template <class T>
MinHeap<T>::MinHeap(int sz) {
// ���캯����������СΪ sz �Ķ�
	maxHeapSize = (10 < sz) ? sz : 10;
	heap = new T[maxHeapSize];	// �����ѿռ�
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;	exit(1);
	}
	currentSize = 0;	// ������ǰ��С
}

template <class T>
MinHeap<T>::MinHeap (T arr[ ], int n) {
// ���캯���������� arr[ ] ���Ԫ�ش�����
	
}

template <class T>
bool MinHeap<T>::Insert (const T x ) {
// �� x ���뵽��С����
	
	return true;
}

template <class T>
bool MinHeap<T>::Remove (T& x) {
// �Ӷ���ɾ��Ԫ�أ����� x ����

	return true;	// ������СԪ��
}

template <class T>
bool MinHeap<T>::IsEmpty ( ) const {
// �жѿշ�
	return  true;
}
template <class T>
bool MinHeap<T>::IsFull ( ) const {
// �ж�����
	return true;
}
template <class T>
void MinHeap<T>::MakeEmpty ( ) {
// �ÿն�

}

void main(void) {
	
	MinHeap<int> mp(10);

	int k[ ] = {4, 2, 5, 8, 3, 6, 10, 14};

	int i;
	for(i = 0; i < 8; i++) {
		mp.Insert(k[i]);
		cout << "���� " << k[i] << " ��\t";
		mp.Display( );
	}

	cout << "*******************************************************" << endl;
	int a;
	mp.Remove(a);
	cout << "�� 1 ��ɾ��������Ϊ��" << a << "����Ϊ��";
	mp.Display( );

	mp.Remove(a);
	cout << "�� 2 ��ɾ��������Ϊ��" << a << "����Ϊ��";
	mp.Display( );


	cout << endl << endl;

	int data[] = {100, 86, 48, 73, 35, 39, 42, 57, 66, 21};
	cout << "����ǰ����";
	for(i = 0; i < 10; i++) {
		cout << data[i] << "  ";
	}
	cout << endl;

	MinHeap<int> mp1(data, 10);
	cout << "����Ѻ����";
	mp1.Display();
	cout << endl;

	system("pause");
}