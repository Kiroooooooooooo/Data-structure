#include <iostream>
#include <fstream>
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

	void CreatePreOrder (ifstream& in){ CreateBinTree(in, root); }
	~BinaryTree ( ) { destroy(root); }			// ��������

public:
	bool IsEmpty ( );				// �ж������շ�
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// ��������Ů	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//��������Ů
	BinTreeNode<T> *getRoot( );		//ȡ��
	int Height ( );					// �����߶�
	int Size ( );					// ������
	void PreOrder ( );				//ǰ�����
	void InOrder ();				//�������
	void PostOrder ( );				//�������
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
	//����һ�����������־����λ@
	BinaryTree<char> T('@');

	//�жϴ�ʱ���Ƿ�Ϊ��
	if( T.IsEmpty() )
	{
		cout << "��ʱ������Ϊ��" << endl;
	}

	//��ȡ�ļ��е����ݣ���������֯�����Ľṹ
	ifstream ifs("tree.txt");
	if(!ifs.is_open( ))
	{
		cout<<"���Ҳ���������ṹ���ļ���";
		system("pause");
		return 0;
	}
	T.CreatePreOrder(ifs);
	ifs.close( );
	
	//�жϴ�ʱ���Ƿ�Ϊ��
	if( !T.IsEmpty() )
	{
		cout << "��ʱ��������Ϊ��" << endl;
	}
	//������ڵ������
	cout << T.getRoot() ->data << endl;

	//������ڵ����Һ��ӵ�����
	cout << T.getRoot() ->leftChild ->data << endl;
	cout << T.getRoot() ->rightChild ->data << endl;

	//������һЩ����
	cout << "ǰ�����:";
	T.PreOrder();
	cout << endl;

	cout << "�������:";
	T.InOrder();
	cout << endl;

	cout << "�������:";
	T.PostOrder( );
	cout << endl;

	cout << "�ڵ���:";
    cout << T.Size() << endl;

	cout << "���ĸ�:";
    cout << T.Height() << endl;

	system("pause");
}
