#ifndef _BINARY_TREE_CPP
#define _BINARY_TREE_CPP

#include <iostream>
#include <fstream>
#include <assert.h>

#include "BinaryTree.h"

template<class T> 
void BinaryTree<T>::destroy (BinTreeNode<T> * subTree){
// ˽�к���: ɾ����ΪsubTree������
	if (subTree != NULL) {
		destroy (subTree->leftChild);	// ɾ��������
		destroy (subTree->rightChild);	// ɾ��������
		delete subTree;					// ɾ�������
	}
}

template<class T> 
void BinaryTree<T>::CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree) {
// ˽�к���: �Եݹ鷽ʽ������������
	T item;
	if ( !in.eof ( ) ) {	// δ����, ���벢����
		in >> item;			// ���������ֵ
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);	// ���������
			if (subTree == NULL) {  cerr << "�洢�����!" << endl;  exit (1);}
			CreateBinTree (in, subTree->leftChild);	// �ݹ齨��������
			CreateBinTree (in, subTree->rightChild);// �ݹ齨��������
		}
		else subTree = NULL;						// ���ָ���������ָ��
     }
};
//*************************************************************************************************************
template<class T> 
bool BinaryTree<T>::IsEmpty ( )
{
	return false;
}

template<class T> 
BinTreeNode<T> * BinaryTree<T>::getRoot( )
{
	return NULL;
}

template<class T> 
int BinaryTree<T>::Height( )
{
	return -1;
}

template<class T>
int BinaryTree<T>::Size( )
{
	return -1;
}

template<class T>
void BinaryTree<T>::PreOrder()
{

}

template<class T>
void BinaryTree<T>::InOrder()
{

}

template<class T>
void BinaryTree<T>::PostOrder()
{
	
}

#endif