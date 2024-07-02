#ifndef SEQLIST_H
#define SEQLIST_H

template <class T>
class SeqList
{
private:
	T * array;
	int max;
	int last;
public:
	SeqList(int max);
	SeqList(SeqList & L);
	~SeqList();
	void output();
	bool insert(T & num , int position);
	bool remove(int position , T & x);
	int size()const;
	int search(T& x)const;
	bool getData(int i,T &x)const;
	void setData(int i,T &x);
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	int length()const;
};

#endif
