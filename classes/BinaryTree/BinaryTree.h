#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <fstream>
#include <iostream>
using namespace std;

template <class T> 
struct BinTreeNode {	// ����������ඨ��
	T data;	 								// ������
	BinTreeNode<T> *leftChild, *rightChild;	// ����Ů������Ů����

	BinTreeNode ( ): leftChild(NULL), rightChild(NULL){  }  // ���캯��
	BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL): data(x), leftChild(l), rightChild(r){ }
};

template <class T> 
class BinaryTree {		// �������ඨ��
private:
	BinTreeNode<T> *root;	// �������ĸ�ָ��
	T  RefValue;			// ��������ֹͣ��־
private:
	void CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree);	// ���ļ����뽨��
	void destroy (BinTreeNode<T> *subTree);

public:
	BinaryTree ( ) : root (NULL) { }			// ���캯��
	BinaryTree (T value) : RefValue(value), root(NULL) {  }	// ���캯��
	//BinaryTree (BinaryTree<T>& s);				// ���ƹ��캯��

	void CreatePreOrder (ifstream& in){CreateBinTree(in, root);}
	~BinaryTree ( ) { destroy(root); }			// ��������

//****************************************************************************************
public:
	bool IsEmpty ( );				// �ж������շ�
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// ��������Ů	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//��������Ů
	BinTreeNode<T> *getRoot( );		//ȡ��
	int Height ( );					// �����߶�
	int Size ( );					// ������
	void PreOrder ();				//ǰ�����
	void InOrder ();				//�������
	void PostOrder ();				//�������
};


#include "BinaryTree.cpp"

#endif