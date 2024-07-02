#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <fstream>
#include <iostream>
using namespace std;

template <class T> 
struct BinTreeNode {	// 二叉树结点类定义
	T data;	 								// 数据域
	BinTreeNode<T> *leftChild, *rightChild;	// 左子女、右子女链域

	BinTreeNode ( ): leftChild(NULL), rightChild(NULL){  }  // 构造函数
	BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL): data(x), leftChild(l), rightChild(r){ }
};

template <class T> 
class BinaryTree {		// 二叉树类定义
private:
	BinTreeNode<T> *root;	// 二叉树的根指针
	T  RefValue;			// 数据输入停止标志
private:
	void CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree);	// 从文件读入建树
	void destroy (BinTreeNode<T> *subTree);

public:
	BinaryTree ( ) : root (NULL) { }			// 构造函数
	BinaryTree (T value) : RefValue(value), root(NULL) {  }	// 构造函数
	//BinaryTree (BinaryTree<T>& s);				// 复制构造函数

	void CreatePreOrder (ifstream& in){CreateBinTree(in, root);}
	~BinaryTree ( ) { destroy(root); }			// 析构函数

//****************************************************************************************
public:
	bool IsEmpty ( );				// 判二叉树空否
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// 返回左子女	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//返回右子女
	BinTreeNode<T> *getRoot( );		//取根
	int Height ( );					// 求树高度
	int Size ( );					// 求结点数
	void PreOrder ();				//前序遍历
	void InOrder ();				//中序遍历
	void PostOrder ();				//后序遍历
};


#include "BinaryTree.cpp"

#endif