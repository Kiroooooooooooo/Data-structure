#include <iostream>
using namespace std;


//**************************************
void input(int * set , int length)
{
	for(int i = 0; i < length; i++)
	{
		cin >> set[i];
	}
}

template<class T>
class SeqList{
	private:
	    T * array;
    	int max;
	    int last;
    public:
	    SeqList(int max);
	    ~SeqList();
	    int size();
	    int length();
	    int search(T& x);
	    void output();
	    bool insert(int index,T &x);
	    bool remove(int index,T & x);
	    bool getData(int index,T &x);
	    bool setData(int index,T &x);
	    bool isFull();
	    bool isEmpty();
	    void makeEmpty();
};

template <class T>
SeqList<T>::SeqList(int max){
	this ->array = new T[max];
	this ->max = max;
	this ->last = -1;
}

template <class T>
SeqList<T>::~SeqList(){
	delete [] this ->array;
}

template <class T>
int SeqList<T>::size(){
	return max;
}

template <class T>
int SeqList<T>::length(){
	return last+1;
}

template <class T>
int SeqList<T>::search(T& x){
	for(int i = 0; i <= last; i++){
		if(array[i]==x)
		return x;
		else if(i==last)
		return -1;
	}
}

template <class T>
bool SeqList<T>::getData(int index,T &x){ 
    if(index<0||index>last) {
        return false;
    }
	else 
	x=array[index];
	return true;
}

    
template <class T>
void SeqList<T>::output(){
	for(int i = 0; i<=last;i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

template <class T>
bool SeqList<T>::insert(int index,T &x){
	if(index<0||index> last + 1)
	    return false;
	else
	    for(int i = last; i >= index; i--){
		    array[i + 1] = array[i];
	    }
	array[index] = x;
	last ++;
	return true;
}

template <class T>
bool SeqList<T>::remove(int index, T &x){
	if(index< 0 || index> last)return false;
	else
		x = array[index];
	for(int i = index; i < last; i++){
		array[i] = array[i + 1];
	}
	last --;
	return true;
}

template <class T>
bool SeqList<T>::isFull(){
	if(last==max-1)
	    return true;
	else
	    return false;
}

template <class T>
bool SeqList<T>::isEmpty(){
	if(last==-1)
	    return true;
	else
	    return false;
}


template <class T>
void SeqList<T>::makeEmpty(){
	last=-1;
}
	
template<class T>
bool SeqList<T>::setData(int index,T & x){
	if(index< 0 || index> last+1||last==max-1)
	    return false;
	else
	    array[index] = x;
	    return true;
}
    
 

int main()
{
	int set_1[10];
	int set_2[10];
	cout << "输入集合1中的内容" << endl;
	input(set_1 , sizeof(set_1)/sizeof(int));
	cout << "输入集合2中的内容" << endl;
	input(set_2 , sizeof(set_2)/sizeof(int));
	//请完成接下来的代码，在控制台输出两个集合的交集和并集
	SeqList<int>Seq1(10);
	SeqList<int>Seq2(10);
	SeqList<int>Seq3(10);
	SeqList<int>Seq4(10);
	for(int i=0;i<1;i++){
		Seq1.insert(i,set_1[i]);
		Seq2.insert(i,set_2[i]);
		Seq4.insert(i,set_2[i]);
	}
	for(int i=0;i<10;i++){
		int x;
		Seq1.getData(i,x);
		if(x==Seq2.search(x)){
			Seq3.insert(0,x);
		}
		if(x!=Seq2.search(x)){
			Seq4.insert(i+10,x);
		}
	}
	Seq3.output();
    cout<<endl;
}
