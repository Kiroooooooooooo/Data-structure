#ifndef _BINARY_TREE_CPP
#define _BINARY_TREE_CPP

#include <iostream>
#include <fstream>
#include <assert.h>

#include "BinaryTree.h"

template<class T> 
void BinaryTree<T>::destroy (BinTreeNode<T> * subTree){
// 私有函数: 删除根为subTree的子树
	if (subTree != NULL) {
		destroy (subTree->leftChild);	// 删除左子树
		destroy (subTree->rightChild);	// 删除右子树
		delete subTree;					// 删除根结点
	}
}

template<class T> 
void BinaryTree<T>::CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree) {
// 私有函数: 以递归方式建立二叉树。
	T item;
	if ( !in.eof ( ) ) {	// 未读完, 读入并建树
		in >> item;			// 读入根结点的值
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);	// 建立根结点
			if (subTree == NULL) {  cerr << "存储分配错!" << endl;  exit (1);}
			CreateBinTree (in, subTree->leftChild);	// 递归建立左子树
			CreateBinTree (in, subTree->rightChild);// 递归建立右子树
		}
		else subTree = NULL;						// 封闭指向空子树的指针
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