#include<iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node *left;
		Node *right;
	public:
		Node();
		~Node();
		friend Node *insert(Node *t, int x);
		friend void preorder(Node *t);
		friend void inorder(Node *t);
		friend void postorder(Node *t);
		friend Node *search(Node *t, int key);
};
Node::Node()
{
	
}
Node::~Node()
{
	
}
Node *insert(Node *t, int x)
{
	if(!t)
	{
		Node *temp = new Node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else
	{
		if(x < t->data)
		   t->left = insert(t->left,x);
		else
		   t->right = insert(t->right,x);
	}
}
void preorder(Node *t)
{
	if(t)
	{
		cout<<t->data<<"  ";
		preorder(t->left);
		preorder(t->right);
	}
	
}
void inorder(Node *t)
{
	if(t)
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	
}
void postorder(Node *t)
{
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	}
	
}
Node *search(Node *t, int key)
{
	if(t)
	{
		if(key == t->data)
		return t;
		else if (key < t ->data)
		return search(t->left,key);
		else return search(t->right, key);
	}
	else return NULL;
}
int main()
{
	Node *t = NULL;
	int n, x, key;
	cout<<"Nhap so luong phan tu: "<< endl;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Nhap so: "<<i+1<<endl;
		cin>>x;
		t = insert(t, x);
	}
	preorder(t);
	cout<<endl;
	inorder(t);
	cout<<endl;
	postorder(t);
	cout<<endl;
	cout<<"Nhap so can tim: ";
	cin>>key;
	if(search(t, key))
	cout<<"So co trong cay"<<endl;
	else cout<<"Khong tim thay so!";
	system("pause");
	return 0;
}