#include<iostream>
using namespace std;

template <class T>
struct LinkNode{
	T data;
	LinkNode <T>* link;
	LinkNode(T elem,LinkNode<T> * ptr=NULL){
	data=elem;
	link=ptr;
	}
};

template <class T>
class LinkedQueue{
	protected:
		LinkNode<T>* front;
		LinkNode<T>* rear;
	public:
		LinkedQueue();
		bool getfront(T& x);
	    void EnQueue(T& X);
		bool DeQueue(T& x);
		bool isEmpty();
		void makeEmpty();
};

template <class T>
LinkedQueue<T>::LinkedQueue(){
	rear = NULL;
	front = NULL;
}

template <class T>
bool LinkedQueue<T>::getfront(T& x){
	if(front == NULL)
	return false;
	else
	x = front -> data;
	return true;
}

template <class T>
void LinkedQueue<T>::EnQueue(T& x){
	if(front == NULL){
		front = rear = new LinkNode<T>(x); 
	}
	else
	rear -> link = new LinkNode<T>(x);
	
}

template <class T>
bool LinkedQueue<T>::DeQueue(T& x){
	if(front == NULL)
	return false;
	else{
	LinkNode<T>* p = front;
	x = front -> data;
	front = front -> link;
	delete p;
	return true;
}
}

template <class T>
bool LinkedQueue<T>::isEmpty(){
	if(front == NULL)
	return true;
	else
	return false;
}

template <class T>
void LinkedQueue<T>::makeEmpty(){
	LinkNode<T>* p;
	while(front != NULL){
		p = front;
		front = front -> link;
		delete p ; 
	}
}

int main() {
	LinkedQueue<int> list;
	if (list.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	for (int i = 0; i <5; i++){
		list.EnQueue(i);
	}
	if (list.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
	int a;
	list.getfront(a);
	cout << "链式队列队头为" << a << endl;
	int b;
	list.DeQueue(b);
	cout << b << endl;
	list.getfront(a);
	cout << "链式队列队头为" << a << endl;
	list.makeEmpty();
	if (list.isEmpty())cout << "队列为空" << endl;
	else cout << "队列不为空" << endl;
}
