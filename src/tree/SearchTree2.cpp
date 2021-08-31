#include<iostream>
using namespace std;

// khai bÃ¡o cáº¥u trÃºc 1 cÃ¡i node trong cÃ¢y nhá»‹ phÃ¢n tÃ¬m kiáº¿m
typedef class NODE *TREE;
class NODE
{   
	private: 
        int data; // dá»¯ liá»‡u chá»©a trong 1 cÃ¡i node
	    NODE *pLeft; // con trá» liÃªn káº¿t vá»›i cÃ¡i node bÃªn trÃ¡i <=> cÃ¢y con trÃ¡i
	    NODE *pRight; // con trá» liÃªn káº¿t vá»›i cÃ¡i node bÃªn pháº£i <=> cÃ¢y con pháº£i
	public:
	    friend void KhoiTaoCay(TREE &t);
	    friend void ThemNodeVaoCay(TREE &t, int x);
	    friend void NLR(TREE t);
	    friend NODE *TimKiem(TREE t, int x);
        friend void Node_Co_2_Con(TREE t);
        friend void Node_Co_1_Con(TREE t);
        friend void Node_La(TREE t);
        friend void DiTimNodeTheMang(TREE &X, TREE &Y);
	    friend int TimMax(TREE t);
        friend void XoaNode(TREE &t, int data);
        friend void Menu(TREE &t);
};


void KhoiTaoCay(TREE &t){ // hÃ m khá»Ÿi táº¡o cÃ¢y nhá»‹ phÃ¢n tÃ¬m kiáº¿m
	t = NULL;
}
void ThemNodeVaoCay(TREE &t, int x){ // hÃ m thÃªm 1 pháº§n tá»­ vÃ o cÃ¢y

	if (t == NULL){ // náº¿u cÃ¢y rá»—ng
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else{
		if (x < t->data) // náº¿u pháº§n tá»­ thÃªm vÃ o náº¿u nhá» hÆ¡n nÃºt gá»‘c sáº½ duyá»‡t qua bÃªn trÃ¡i		
			ThemNodeVaoCay(t->pLeft, x); // Äá»‡ quy sang trÃ¡i 	
		else if (x > t->data) // náº¿u pháº§n tá»­ thÃªm vÃ o náº¿u nhá» hÆ¡n nÃºt gá»‘c sáº½ duyá»‡t qua bÃªn pháº£i
			ThemNodeVaoCay(t->pRight, x); // Äá»‡ quy sang pháº£i	
	}
}

// hÃ m xuáº¥t pháº§n tá»­ trong cÃ¢y nhá»‹ phÃ¢n tÃ¬m kiáº¿m
void NLR(TREE t){ // Duyá»‡t theo Node Left Right
	if (t != NULL){
		// xá»­ lÃ­
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// náº¿u node cÃ³ tá»“n táº¡i trong cÃ¢y thÃ¬ tráº£ vá» cÃ¡i node Ä‘Ã³ - cÃ²n khÃ´ng tá»“n táº¡i thÃ¬ tráº£ vá» NULL
NODE *TimKiem(TREE t, int x){
	if (t == NULL) // náº¿u cÃ¢y rá»—ng
		return NULL;
	else{
		// náº¿u pháº§n tá»­ cáº§n tÃ¬m kiáº¿m mÃ  nhá» hÆ¡n node gá»‘c thÃ¬ duyá»‡t sang bÃªn trÃ¡i Ä‘á»ƒ tÃ¬m
		if (x < t->data)
			TimKiem(t->pLeft, x); // Äá»‡ quy sang bÃªn trÃ¡i tÃ¬m
		// náº¿u pháº§n tá»­ cáº§n tÃ¬m kiáº¿m mÃ  lá»›n hÆ¡n node gá»‘c thÃ¬ duyá»‡t sang bÃªn trÃ¡i Ä‘á»ƒ tÃ¬m	
		else if (x > t->data)
			TimKiem(t->pRight, x); // Äá»‡ quy sang bÃªn pháº£i tÃ¬m
		else // x == t->data	
			return t; // tráº£ vá» node cáº§n tÃ¬m kiáº¿m	
	}
}

// xuáº¥t cÃ¡c node cÃ³ 2 con
void Node_Co_2_Con(TREE t){
	if (t != NULL){
		// Node cÃ³ tá»“n táº¡i pháº§n tá»­ con trÃ¡i vÃ  con pháº£i 
		if (t->pLeft != NULL && t->pRight != NULL){
			cout << t->data << "  ";
		}
		// duyá»‡t sang cÃ¢y con trÃ¡i cá»§a node hiá»‡n táº¡i
		Node_Co_2_Con(t->pLeft);
		// duyá»‡t sang cÃ¢y con pháº£i cá»§a node hiá»‡n táº¡i 
		Node_Co_2_Con(t->pRight); 
	}
}


// xuáº¥t cÃ¡c node cÃ³ 1 con
void Node_Co_1_Con(TREE t){
	if (t != NULL){
		// Node cÃ³ tá»“n táº¡i pháº§n tá»­ hoáº·c con trÃ¡i hoáº·c con pháº£i
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << "  ";
		}
		// duyá»‡t (Ä‘á»‡ quy) sang cÃ¢y con trÃ¡i cá»§a node hiá»‡n táº¡i
		Node_Co_1_Con(t->pLeft); 
		//duyá»‡t (Ä‘á»‡ quy) sang cÃ¢y con pháº£i cá»§a node hiá»‡n táº¡i
		Node_Co_1_Con(t->pRight);
	}
}

// xuáº¥t cÃ¡c node lÃ¡
void Node_La(TREE t){
	if (t != NULL){
        // Node khÃ´ng tá»“n táº¡i pháº§n tá»­
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << "  ";
		}
		// duyá»‡t sang cÃ¢y con trÃ¡i cá»§a node hiá»‡n táº¡i
		Node_La(t->pLeft);
		// duyá»‡t sang cÃ¢y con pháº£i cá»§a node hiá»‡n táº¡i
		Node_La(t->pRight); 
	}
}

// hÃ m tÃ¬m node tháº¿ máº¡ng
void DiTimNodeTheMang(TREE &X, TREE &Y){ // NODE Y lÃ  node tháº¿ máº¡ng cho node cáº§n xÃ³a
                                         // TÃ¬m ra node trÃ¡i nháº¥t cá»§a cÃ¢y CON PHáº¢I)
                                         // TÃ¬m ra node trÃ¡i nháº¥t cá»§a cÃ¢y CON PHáº¢I)
	if (Y->pLeft != NULL)
		DiTimNodeTheMang(X, Y->pLeft);// tÃ¬m ra node trÃ¡i nháº¥t 
	else{ 
		X->data = Y->data; // cáº­p nháº­t data cá»§a node cáº§n xÃ³a chÃ­nh lÃ  data cá»§a node tháº¿ máº¡ng
		X = Y; // cho node X lÃ  Node mÃ  chÃºng ta sáº½ Ä‘i xÃ³a trá» Ä‘áº¿n node tháº¿ máº¡ng ==> ra khá»i hÃ m thÃ¬ ta sáº½ xÃ³a node X
		Y = Y->pRight; // Cáº­p nháº­t láº¡i má»‘i liÃªn káº¿t cho node cha cá»§a node tháº¿ máº¡ng(mÃ  chÃºng ta sáº½ xÃ³a) vá»›i node con cá»§a node tháº¿ máº¡ng	
	}
}
int TimMax(TREE t) // VÃ¬ CÃ¡c nhÃ¡nh con bÃªn pháº£i luÃ´n luÃ´n lá»›n hÆ¡n Node gá»‘c
{
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return TimMax(t->pRight); // Duyá»‡t Ä‘áº¿n node cuá»‘i cÃ¹ng nháº¥t bÃªn cÃ¢y con pháº£i ==> Äi tÃ¬m Max
}

void XoaNode(TREE &t, int DaTa){ // data lÃ  giÃ¡ trá»‹ cá»§a cÃ¡i node cáº§n xÃ³a
	if (t == NULL)
		return;
	else{
		if (DaTa < t->data) // náº¿u nhÆ° data nhá» hÆ¡n node gá»‘c	
			XoaNode(t->pLeft, DaTa); // Äá»‡ quy sang nhÃ¡nh trÃ¡i cá»§a cÃ¢y 	
		else if (DaTa > t->data) // náº¿u nhÆ° data lá»›n hÆ¡n node gá»‘c			
			XoaNode(t->pRight, DaTa); // Äá»‡ quy sang nhÃ¡nh pháº£i cá»§a cÃ¢y 	
		else{ // data == t->data - ÄÃ£ tÃ¬m ra cÃ¡i node cáº§n xÃ³a
			NODE *X = t; // node X lÃ  node tháº¿ máº¡ng cÅ©ng lÃ  Node chÃºng ta sáº½ xÃ³a 
			if (t->pLeft == NULL){ // ÄÃ¢y lÃ  cÃ¢y cÃ³ 1 con chÃ­nh lÃ  con pháº£i
				// duyá»‡t sang pháº£i cá»§a cÃ¡i node cáº§n xÃ³a Ä‘á»ƒ cáº­p nháº­t má»‘i liÃªn káº¿t giá»¯a node 
				// cha cá»§a node cáº§n xÃ³a vá»›i node con cá»§a node cáº§n xÃ³a
				t = t->pRight; 
			}
			else if (t->pRight == NULL) // ÄÃ¢y lÃ  cÃ¢y cÃ³ 1 con chÃ­nh lÃ  con trÃ¡i
				// duyá»‡t sang trÃ¡i cá»§a cÃ¡i node cáº§n xÃ³a Ä‘á»ƒ cáº­p nháº­t má»‘i liÃªn káº¿t giá»¯a node 
				// cha cá»§a node cáº§n xÃ³a vá»›i node con cá»§a node cáº§n xÃ³a
				t = t->pLeft;
			else // node cáº§n xÃ³a lÃ  node cÃ³ 2 con
				DiTimNodeTheMang(X, t->pRight);
			delete X; // xÃ³a node cáº§n xÃ³a
		}
	}
}
// hÃ m nháº­p cÃ¢y nhá»‹ phÃ¢n tÃ¬m kiáº¿m
void Menu(TREE &t)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============ MENU ============";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Duyet cay";
		cout << "\n3. Tim kiem phan tu trong cay";
		cout << "\n4. Node co 2 con la: ";
		cout << "\n5. Node co 1 con la: ";
		cout << "\n6. Node la la:";
		cout << "\n7. Tim Node Max";
		cout << "\n8. Xoa Node bat ki";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\t NODE CO 2 CON: ";
			Node_Co_2_Con(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\t NODE CO 1 CON: ";
			Node_Co_1_Con(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\t NODE LA: ";
			Node_La(t);
			system("pause");
		}
		else if (luachon == 7)
		{
	
			cout << "\nMAX: " << TimMax(t);
			system("pause");
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\nNhap gia tri can xoa: ";
			cin >> x;
			XoaNode(t, x);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}