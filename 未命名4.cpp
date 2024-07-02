#include<iostream>
using namespace std;
template <class T>
class SeqQueue{
	protected:
		int rear,front;
		T* elements;
		int maxSize;
	public:
		SeqQueue(int max);
		bool getFront(T& x);
		bool EnQueue(T& x);
		bool DeQueue(T& x);
		bool isEmpty();
		bool isFull();
		void makeEmpty();	
};

template <class T>
SeqQueue<T>::SeqQueue(int max){
	 if (max < 0) { 
	 exit(1); 
	 }
	front = 0;
	rear = 0;
	maxSize = max;
	elements = new T[maxSize];
} 

template <class T>
bool SeqQueue<T>::getFront(T& x){
	if(front == rear)
	return false;
	else
	x = elements[front];
}
template <class T>
bool SeqQueue<T>::EnQueue(T& x){
	if((front+1)%maxSize == front)
	return false;
	else
	elements[rear] = x;
	rear = (rear+1)%maxSize;
	return true;
}
template <class T>
bool SeqQueue<T>::DeQueue(T& x){
	if(front == rear)
	return false;
	else
	x = elements[front];
	front = (front+1)%maxSize;
	return true;
}
template <class T>
bool SeqQueue<T>::isEmpty(){
	if(front == rear)
	return true;
	else
	return false;
}
template <class T>
bool SeqQueue<T>::isFull(){
	if((front+1)%maxSize == front)
	return true;
	else
	return false;
} 

template <class T>
void SeqQueue<T>::makeEmpty(){
	front = rear = 0;
}

int main() {
	SeqQueue<int> seq(10);
	if (seq.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	if (seq.isFull())cout << "队列已满" << endl;
	else cout << "队列未满" << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.EnQueue(i);
	}
	if (seq.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	if (seq.isFull())cout << "队列已满" << endl;
	else cout << "队列未满" << endl;
	int a;
	seq.getFront(a);
	cout << "队头元素为：" << a << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.DeQueue(i);
	}
	if (seq.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	if (seq.isFull())cout << "队列已满" << endl;
	else cout << "队列未满" << endl;
	seq.makeEmpty();
	if (seq.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	if (seq.isFull())cout << "队列已满" << endl;
	else cout << "队列未满" << endl;
}
