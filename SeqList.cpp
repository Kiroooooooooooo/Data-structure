#ifndef SEQLIST_CPP
#define SEQLIST_CPP

	#include <iostream>
	using namespace std;

    SeqList <int> seq(5);
	
	template <class T>
	SeqList<T>::SeqList(int max)
	{
		this ->array = new T[max];
		if(array == NULL)
		{
			cerr << "´¢´æ·ÖÅä´íÎó£¡"<< endl;
			exit(1);
		}
		this ->max = max;
		this ->last = -1;
	}
    
	
	template <class T>
	SeqList<T>::SeqList(SeqList & L)
	{
		this ->max = L.max;
		this ->last = L.last;
		this ->array = new T[max];
		if(array == NULL)
		{
			cerr << "´¢´æ·ÖÅä´íÎó£¡"<< endl;
			exit(1);
		}
		for(int i = 0; i <= last; i++)
		{
			this ->array[i] = L.array[i];
		}
	}

	template <class T>
	SeqList<T>::~SeqList()
	{
		delete [] this ->array;
	}

	template <class T>
	int SeqList<T>::size()const
    {
	    return seq.max;
	}

	template <class T>
	int SeqList<T>::length()const
    {
	    return last+1;
	}

	template <class T>
	int SeqList<T>::search(T& x)const
    {
	   for(int i = 0; i <= last; i++)
	        if(array[i] == x)
			return i ;
		return 0;
	}

	template <class T>
	bool SeqList<T>::getData(int i,T &x)const
	{ 
        if(i >=0&& i <= last+1) {
        x = array[i ];
        return true;
    }else return false;}

    
	template <class T>
	void SeqList<T>::output()
	{
		for(int i = 0; i <= last; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	template <class T>
	bool SeqList<T>::insert(T & num , int position)
	{
		if(last == max - 1)return false;
		if(position < 0 || position > last + 1)return false;
		for(int i = last; i >= position; i--)
		{
			array[i + 1] = array[i];
		}
		array[position] = num;
		last ++;
		return true;
	}

	template <class T>
	bool SeqList<T>::remove(int position , T &x)
	{
		if(last == -1)return false;
		if(position < 0 || position > last)return false;
		x = array[position];
		for(int i = position; i < last; i++)
		{
			array[i] = array[i + 1];
		}
		last --;
		return true;
	}

	template <class T>
	bool SeqList<T>::isFull()
    {
	return seq.last == seq.max;
    }

	template <class T>
	bool SeqList<T>::isEmpty()
    {
	return seq.last == 0;
    }


	template <class T>
	void SeqList<T>::makeEmpty()
    {
	    seq.last = 0;
    }
	
	template<class T>
	void SeqList<T>::setData(int i,T & x){
		if(i< 0 || i> last)
		return;
		array[i] = x;
		}


#endif
