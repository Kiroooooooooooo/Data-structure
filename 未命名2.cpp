#include <iostream>
using namespace std;

template <class T>
class SeqStack{
	private:
		T* elements;
		int top;
		int maxSize;
	public:
		SeqStack(int sz);
		~SeqStack();
		bool Push(T& x);
		bool Pop(T& x);
		bool getTop(T& x);
		bool IsEmpty();
		bool IsFull();
		void makeEmpty();
};

template <class T>
SeqStack<T>::SeqStack(int sz){
    if (sz < 0) { exit(1); }
	top = -1;
	maxSize = sz;
	elements = new T[maxSize];
}

template <class T>
SeqStack<T>::~SeqStack(){
	delete[]elements;
}

template <class T>
bool SeqStack<T>::Push(T& x){
	if(top == maxSize-1)
		return false;
	else
		elements[++top] = x;
	return true;
}

template <class T>
bool SeqStack<T>::Pop(T& x){
	if(top == -1)
		return false;
	else
		x = elements[top--];
	return true;
}

template <class T>
bool SeqStack<T>::getTop(T& x){
		if(top == -1)
		return false;
	else
		x = elements[top];
	return true;
}

template <class T>
bool SeqStack<T>::IsEmpty(){
	if(top == -1)
		return true;
	else
		return false;
}

template <class T>
void SeqStack<T>::makeEmpty(){
	top = -1;
}

template <class T>
bool SeqStack<T>::IsFull(){
	if(top == maxSize-1)
		return true;
	else
		return false;
}

int main() {
	SeqStack<int> seq(10);
	if (seq.IsEmpty())cout << "Ë³ÐòÕ»Îª¿Õ" << endl;
	else cout << "Ë³ÐòÕ»²»Îª¿Õ" << endl;
	if (seq.IsFull())cout << "Ë³ÐòÕ»ÒÑÂú" << endl;
	else cout << "Ë³ÐòÕ»Î´Âú" << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.Push(i);
	}
	if (seq.IsEmpty())cout << "Ë³ÐòÕ»Îª¿Õ" << endl;
	else cout << "Ë³ÐòÕ»²»Îª¿Õ" << endl;
	if (seq.IsFull())cout << "Ë³ÐòÕ»ÒÑÂú" << endl;
	else cout << "Ë³ÐòÕ»Î´Âú" << endl;
	int a;
	seq.getTop(a);
	cout << "Õ»¶¥ÔªËØÎª£º" << a << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.Push(i);
	}
	if (seq.IsEmpty())cout << "Ë³ÐòÕ»Îª¿Õ" << endl;
	else cout << "Ë³ÐòÕ»²»Îª¿Õ" << endl;
	if (seq.IsFull())cout << "Ë³ÐòÕ»ÒÑÂú" << endl;
	else cout << "Ë³ÐòÕ»Î´Âú" << endl;
	seq.makeEmpty();
	if (seq.IsEmpty())cout << "Ë³ÐòÕ»Îª¿Õ" << endl;
	else cout << "Ë³ÐòÕ»²»Îª¿Õ" << endl;
	if (seq.IsFull())cout << "Ë³ÐòÕ»ÒÑÂú" << endl;
	else cout << "Ë³ÐòÕ»Î´Âú" << endl;
}
