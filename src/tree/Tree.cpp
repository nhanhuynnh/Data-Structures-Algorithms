#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *ThemNodeVaoCay(int x)
{
		node *p = new node;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		return p;
}
void Duyet_LNR(node *t)
{
	if (t != NULL)
	{  		
		Duyet_LNR(t->left);
		cout << t->data << " ";
		Duyet_LNR(t->right);
	}
}

int main(){

	node * t = ThemNodeVaoCay(5);
    t->left  = ThemNodeVaoCay(12);
	t->left->left = ThemNodeVaoCay(8);
	t->left->right  = ThemNodeVaoCay(2);
	t->right = ThemNodeVaoCay(11);
	t->right->right = ThemNodeVaoCay(1);
	t->right->left = ThemNodeVaoCay(15);
	int n;
    for(int i = 0; i < n; i++)
	{
        cout<<"Nhap node thu "<<i+1<<": ";
		cin>>n;
		t = ThemNodeVaoCay(n);
	}

    Duyet_LNR(t); 
	system("pause");
	return 0;
}