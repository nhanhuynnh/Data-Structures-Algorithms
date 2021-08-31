#include<iostream>
using namespace std;
// khai bÃ¡o cáº¥u trÃºc cá»§a 1 cÃ¡i node trong stack

class NODE{
    private: 
	   int data; // stack Ä‘ang chá»©a cÃ¡c sá»‘ nguyÃªn
	   NODE *pNext; // con trá» liÃªn káº¿t giá»¯a cÃ¡c node vá»›i nhau
	public:   
       friend class STACK;
};
class STACK // khai bÃ¡o cáº¥u trÃºc cá»§a stack
{ 
    private:
        NODE *pTop; // dÃ¹ng con trá» Ä‘áº§u Ä‘á»ƒ quáº£n lÃ­ stack
    public:
        void KhoiTaoStack(STACK &s); // hÃ m khá»Ÿi táº¡o stack
        NODE *KhoiTaoNode(int x); // hÃ m khá»Ÿi táº¡o 1 cÃ¡i node
        bool IsEmpty(STACK s); // KIá»‚M TRA STACK CÃ“ Rá»–NG HAY KHÃ”NG
        bool Push(STACK &s, NODE *p); // náº¿u danh sÃ¡ch rá»—ng
        bool Pop(STACK &s, int &x);// x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y trong node   
        bool Top(STACK &s, int &x); // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem
        void XuatStack(STACK s); // hÃ m xuáº¥t danh sÃ¡ch stack
        void NhapStack(STACK &s); // hÃ m nháº­p danh sÃ¡ch cÃ¡c sá»‘ nguyÃªn trong stack	       
};	

void STACK::KhoiTaoStack(STACK &s) // hÃ m khá»Ÿi táº¡o stack
{
	s.pTop = NULL;
}        
NODE *STACK::KhoiTaoNode(int x){ // hÃ m khá»Ÿi táº¡o 1 cÃ¡i node
	NODE *p = new NODE();
	if (p == NULL){
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thÃªm giÃ¡ trá»‹ cá»§a biáº¿n x vÃ o trong data cá»§a cÃ¡i node
    p->pNext = NULL;
	return p;
}
bool STACK::IsEmpty(STACK s){ // KIá»‚M TRA STACK CÃ“ Rá»–NG HAY KHÃ”NG 
	// náº¿u danh sÃ¡ch rá»—ng
	if (s.pTop == NULL) // náº¿u danh sÃ¡ch rá»—ng
		return true;
	return false;// danh sÃ¡ch cÃ³ pháº§n tá»­
}
bool STACK::Pop(STACK &s, int &x){ // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y trong node
	if (IsEmpty(s) == true)	// náº¿u danh sÃ¡ch rá»—ng
		return false;
	else{
	    NODE *p = s.pTop; // node p chÃ­nh lÃ  node tháº¿ máº¡ng Ä‘á»ƒ tÃ­ ná»¯a chÃºng ta xÃ³a nÃ³ Ä‘i
	    x = p->data; // gÃ¡n giÃ¡ trá»‹ cá»§a node Ä‘áº§u stack vÃ o biáº¿n x	
	    s.pTop = s.pTop->pNext; // cáº­p nháº­t node Ä‘áº§u stack lÃ  node tiáº¿p theo	
	    delete p; // xÃ³a node Ä‘áº§u stack vá»«a láº¥y 
		
	}
	return true;// láº¥y pháº§n tá»­ Ä‘áº§u stack thÃ nh cÃ´ng
}
bool STACK::Top(STACK &s, int &x){ // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem
	if (IsEmpty(s) == true)	
		return false;   
	x = s.pTop->data; // láº¥y giÃ¡ trá»‹ cá»§a pháº§n tá»­ Ä‘áº§u stack ra Ä‘á»ƒ xem     
	return true;
}
bool STACK::Push(STACK &s, NODE *p){ // náº¿u danh sÃ¡ch rá»—ng
	if (p == NULL)
		return false;
	if (IsEmpty(s) == true){
		s.pTop = p; // node p chÃ­nh lÃ  node Ä‘áº§u stack
	}
	else{ // danh sÃ¡ch Ä‘Ã£ cÃ³ pháº§n tá»­
		p->pNext = s.pTop; // cho con trá» cá»§a node p trá» Ä‘áº¿n node Ä‘áº§u danh sÃ¡ch <=> táº¡o kiÃªn káº¿t
		s.pTop = p; // cáº­p nháº­t láº¡i node Ä‘áº§u
	}
	return true;
}
void STACK::XuatStack(STACK s){ // hÃ m xuáº¥t danh sÃ¡ch stack
	while (IsEmpty(s) == false){
		int x;
		Pop(s, x);
		cout << x << " ";
	}
}
 void STACK::NhapStack(STACK &s){ // hÃ m nháº­p danh sÃ¡ch cÃ¡c sá»‘ nguyÃªn trong stack
	int luachon;
	do{
		do{
			system("cls");
	        cout << "\n\n\t\t ============== Menu ==============";
		    cout << "\n\t1. Them phan tu vao stack - Push";
		    cout << "\n\t2. Xuat danh sach stack - Pop";
		    cout << "\n\t3. Xem thong tin phan tu dau stack - Top";
			cout << "\n\t4. Kiem tra Stack co rong hay khong - Emtpy";
		    cout << "\n\t5. Ket thuc";
		    cout << "\n\n\t\t ============== End ==============";

		    cout << "\nNhap lua chon: ";
		    cin >> luachon;
			if(luachon < 1 || luachon > 5){
				cout<<"\nLua chon khong hop le. Xin kiem tra lai!!!"<<endl;
				system("pause");
						
			}
		}while(luachon < 1 || luachon > 5);
		if (luachon == 1){
		    int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
		    NODE *p = KhoiTaoNode(x);
		    Push(s, p);
		}
		else if (luachon == 2){
			XuatStack(s);
			system("pause");
		}
		else if (luachon == 3){
			int x;
			Top(s, x);
			cout << "\nPhan tu dau stack la: " << x<<endl;
			system("pause");
		}
		else if (luachon == 4){
			if (IsEmpty(s) == true){
				cout << "\nDanh sach dang rong";
			}
	        else{
				cout << "\nDáº¡nh sach dang ton tai phan tu";
			}
			system("pause");	
		}
		else
			break;
	}while(luachon != 5);
}	
int main(){
	STACK s;
	s.KhoiTaoStack(s);
	s.NhapStack(s);

	system("pause");
	return 0;
}