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
class LinkedStack{
	private:
		LinkNode <T>* top;
	public:
		LinkedStack();
		bool getTop(T& x);
		void push(T& x);
		bool pop(T& x);
		bool isEmpty();
		void makeEmpty();
};

template <class T>
LinkedStack<T>::LinkedStack(){
	top = NULL;
} 

template <class T>
bool LinkedStack<T>::getTop(T& x){
	if(top == NULL)
	return false;
	else
	x = top->data;
}

template <class T>
void LinkedStack<T>::push(T& x){
		top = new LinkNode<T>(x, top);
}

template <class T>
bool LinkedStack<T>::pop(T& x){
	if(top == NULL)
	return false;
	LinkNode<T>* p = top;
	top = top->link;
	x = p -> data;
	delete p;
	return true; 
} 
template <class T>
bool LinkedStack<T>::isEmpty(){
	if(top == NULL)
	return true;
	else
	return false;
} 

template <class T>
void LinkedStack<T>::makeEmpty(){
	LinkNode<T>* p;
	while(top != NULL){
		p = top;
		top = top -> link;
		delete p ;
	}
}

int main() {
	LinkedStack<int> list;
	if (list.isEmpty())cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	for (int i = 0; i <5; i++)
	{
		list.push(i);
	}
	if (list.isEmpty())cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	int a;
	list.getTop(a);
	cout << "链式栈首位为" << a << endl;
	int b;
	list.pop(b);
	cout << b << endl;
	list.getTop(a);
	cout << "链式栈首位为" << a << endl;
	list.makeEmpty();
	if (list.isEmpty())cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
}
