#include <iostream>
using namespace std;

template <class T>
struct LinkNode{
    T data;
    LinkNode <T>*link;
    LinkNode(LinkNode<T>*ptr=NULL){
    	link=ptr;
	}
	LinkNode(T item,LinkNode<T>*ptr=NULL){
		data=item;
		link=ptr;
	}
	bool operator==(T x){
		return data==x; 
	}
	bool operator!=(T x){
		return data!=x;
	}
} ;

template <class T>
class LinkList{
	private:
		LinkNode<T>*first;
	public:
		LinkList();
		LinkList(const LinkList<T>&L);
		~LinkList();
		int length();
		LinkNode<T>*search(T &x);
		LinkNode<T>*Locate(int index);
		bool getData(int index,T&x);
		bool setData(int index,T&x);
		bool insert(int index,T&x);
		bool remove(int index,T&x);
		bool isEmpty();
		void makeEmpty();
		void output();
};

template <class T>
LinkList <T>::LinkList(){
	first=new LinkNode<T>;
	if(first==NULL){
		cout<<"����洢�ռ�ʧ�ܣ�"<<endl;
		exit(1);
	}
};

template <class T>
LinkList <T>::LinkList(const LinkList<T>&L){
	if(!(first=new LinkNode<T>(sptr->link->data))){
		cout<<"����洢�ռ�ʧ�ܣ�"<<endl;
		exit(1);
	}
	LinkNode<T>*spre=L.first,*dptr=first;
	while(sptr->link!=NULL){
		if(!(dptr->link=new LinkNode<T<(sptr->link->data))){
			cout<<"����洢�ռ�ʧ�ܣ�"<<endl;
			exit(1);
		}
		dptr=dptr->link;
	    sptr=sptr->link;
	}
	dptr->link=NULL;
};

template <class T>
LinkList<T>::~LinkList(){
	makeEmpty();
	delete first; 
}

template <class T>
int LinkList<T>::length(){
	int cout=0;
	LinkNode<T>*p=first->link;
	while(p!=NULL){
		cout++;
		p=p->link;
	}
	return cout;
};

template <class T>
LinkList<T>::search(T &x){
	LinkNode<T>*current=first->link;
	while(current!=NULL)
	    if(cirrent->data==x) 
		    break;
		else
		    current=current->link;
	return current; 
};

template <class T>
LinkList<T>::Locate(int index){
	if(index<0)
	    return NULL;
	LinkNode<T>*current=first;
	int k=1;
	while(current!=NULL&&k<=index){
		current=current->link;
		k++;
	}
	return current;
};

template <class T>
bool LinkList<T>::getData(int index,T &x){
	if(index<0)
	    return false;
	LinkNod<T>*current=Locate(index);
	if(current==NULL)
	    return false;
	else{
		x=current->data;
		return true;
	}
};

template <class T>
bool LinkList<T>::setData(int index,T &x){
	if(index<=0)
	    return false;
	LinkNod<T>*current=Locate(index);
	if(current==NULL)
	    return false;
	else{
		current->data=x;
		return true;
	}
};

template <class T>
bool LinkList<T>::insert(int index,T &x){
	if(index<=0)
	    return false;
	LinkNod<T>*current=Locate(index-1);
	if(current==NULL)
	    return false;
	LinkNode<T>*newNode=new LinkNode<T>(x);
	if(newNode==NULL)
	    return false;
	newNode->link=current->link;
	current->link=newNode;
	return true;
};

template <class T>
bool LinkList<T>::remove(int index,T &x){
	if(index<=0){
		return false;
	}
	LinkNod<T>*current=Locate(index-1);
	if(current==NULL||current->link==NULL)
	    return false;
	else{
		LinkNode<T>*del=current->link;
		current->link=del->link;
		x=del->data;
		delete del;
		return true;
	}
};

template <class T>
bool LinkList<T>::isEmpty(){
	if(first->link==NULL)
	    return true;
	else{
		return false;
	}
};

template <class T>
void LinkList<T>::makeEmpty(){
	LinkNod<T>*del;
	while(first->link!=NULL){
		del=first->link;
		first->link=del->link;
		delete del;
	}
};

template <class T>
void LinkList<T>::output(){
	LinkNod<T>*current=first->link;
	while(current!=NULL){
		cout<<current->data<<" ";
		current=current->link;
	}
	cout<<endl;
};

int main()
{
	LinkedList <int> seq;	
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;
	
	for(int i = 0; i < 5; i ++)
	{
		seq.insert(i , i);
	}
	cout << "˳���ǰ�������£�" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;

	int x;
	seq.remove(1 , x);
	cout << "˳���ǰ�������£�" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "˳���Ϊ��" << endl;
	else cout << "˳���Ϊ��" << endl;

	cout << "˳����ڵ�ǰԪ�ظ�����" << seq.length() << endl;
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



 
