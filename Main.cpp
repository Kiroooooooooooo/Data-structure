#include <iostream>
#include <fstream>
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

	void CreatePreOrder (ifstream& in){ CreateBinTree(in, root); }
	~BinaryTree ( ) { destroy(root); }			// 析构函数

public:
	bool IsEmpty ( );				// 判二叉树空否
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// 返回左子女	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//返回右子女
	BinTreeNode<T> *getRoot( );		//取根
	int Height ( );					// 求树高度
	int Size ( );					// 求结点数
	void PreOrder ( );				//前序遍历
	void InOrder ();				//中序遍历
	void PostOrder ( );				//后序遍历
private:
    int Height(BinTreeNode<T>*subRoot);
    int Size(BinTreeNode<T>*subRoot);
    void PreOrder(BinTreeNode<T>*subRoot);
    void InOrder (BinTreeNode<T>*subRoot);
    void PostOrder (BinTreeNode<T>*subRoot6 );
};


//****************************************************************************************

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

template<class T> 
bool BinaryTree<T>::IsEmpty ( )
{
	return root==NULL;
}

template<class T> 
BinTreeNode<T> * BinaryTree<T>::getRoot( )
{
	return root;
}

template<class T> 
int BinaryTree<T>::Height( )
{
	return Height(root);
}

template<class T>
int BinaryTree<T>::Size( )
{
	return Size(root);
}

template<class T>
void BinaryTree<T>::PreOrder()
{
    return PreOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder()
{
    return InOrder(root);
}

template<class T>
void BinaryTree<T>::PostOrder( )
{
	return PostOrder(root);
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>*subRoot){
	if(subRoot==NULL) return 0;
	int leftHeight=Height(subRoot->leftChild);
	int rightHeight=Height(subRoot->rightChild);
	return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
}

template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>*subRoot){
    if(subRoot==NULL) return;
	cout<<subRoot->data<<" ";
	PreOrder(subRoot->leftChild);
	PreOrder(subRoot->rightChild);	
}

template<class T>
void BinaryTree<T>::InOrder (BinTreeNode<T>*subRoot){
    if(subRoot==NULL) return;
	InOrder(subRoot->leftChild);
	cout<<subRoot->data<<" ";
	InOrder(subRoot->rightChild);	
}

template<class T>
void BinaryTree<T>::PostOrder (BinTreeNode<T>*subRoot){
    if(subRoot==NULL) return;
    PostOrder(subRoot->leftChild);
	PostOrder(subRoot->rightChild);
	cout<<subRoot->data<<" ";	
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>*subRoot){
	if(subRoot==NULL) return 0;
	int leftSize=Size(subRoot->leftChild);
	int rightSize=Size(subRoot->rightChild);
	return leftSize+rightSize+1;
}
//*************************************************************************************************************

int main(void)
{
	//创建一个空树，其标志符号位@
	BinaryTree<char> T('@');

	//判断此时树是否为空
	if( T.IsEmpty() )
	{
		cout << "此时二叉树为空" << endl;
	}

	//读取文件中的数据，将数据组织成树的结构
	ifstream ifs("tree.txt");
	if(!ifs.is_open( ))
	{
		cout<<"〉找不到存放树结构的文件！";
		system("pause");
		return 0;
	}
	T.CreatePreOrder(ifs);
	ifs.close( );
	
	//判断此时树是否不为空
	if( !T.IsEmpty() )
	{
		cout << "此时二叉树不为空" << endl;
	}
	//输出根节点的数据
	cout << T.getRoot() ->data << endl;

	//输出根节点左右孩子的数据
	cout << T.getRoot() ->leftChild ->data << endl;
	cout << T.getRoot() ->rightChild ->data << endl;

	//对树的一些操作
	cout << "前序遍历:";
	T.PreOrder();
	cout << endl;

	cout << "中序遍历:";
	T.InOrder();
	cout << endl;

	cout << "后序遍历:";
	T.PostOrder( );
	cout << endl;

	cout << "节点数:";
    cout << T.Size() << endl;

	cout << "树的高:";
    cout << T.Height() << endl;

	system("pause");
}
