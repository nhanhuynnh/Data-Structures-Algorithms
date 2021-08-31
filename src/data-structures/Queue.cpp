#include<iostream>
using namespace std;

// khai bÃ¡o cáº¥u trÃºc cá»§a 1 cÃ¡i node trong queue
class NODE
{
    private: 
	int data; // queue Ä‘ang chá»©a cÃ¡c sá»‘ nguyÃªn
	NODE *pNext; // con trá» liÃªn káº¿t giá»¯a cÃ¡c node vá»›i nhau
    public:	
        friend class QUEUE;
};

// khai bÃ¡o cáº¥u trÃºc cá»§a queue
class QUEUE
{
    private:
	NODE *pHead; //  con trá» Ä‘áº§u
	NODE *pTail; // con trá» cuá»‘i 
    public:
        void KhoiTaoQueue(QUEUE &q); // hÃ m khá»Ÿi táº¡o queue
        NODE *KhoiTaoNode(int x); // hÃ m khá»Ÿi táº¡o 1 cÃ¡i node
        bool IsEmpty(QUEUE q); // KIá»‚M TRA QUEUE CÃ“ Rá»–NG HAY KHÃ”NG
        bool Push(QUEUE &q, NODE *p); // THÃŠM 1 PHáº¦N Tá»¬ VÃ€O CUá»I QUEUE- FIFO   
        bool Pop(QUEUE &q, int &x);// x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y trong node 
        bool Top(QUEUE &q, int &x); // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem 
	bool Back(QUEUE &q, int &x); // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem 
        void XuatQueue(QUEUE q); // hÃ m xuáº¥t danh sÃ¡ch queue   
        void NhapQueue(QUEUE &q);// hÃ m nháº­p danh sÃ¡ch cÃ¡c sá»‘ nguyÃªn trong queue        
};
void QUEUE::KhoiTaoQueue(QUEUE &q){ // hÃ m khá»Ÿi táº¡o queue
	q.pHead = NULL;
	q.pTail = NULL;
}
NODE *QUEUE::KhoiTaoNode(int x){ // hÃ m khá»Ÿi táº¡o 1 cÃ¡i node
	NODE *p = new NODE();
	if (p == NULL){
	    cout << "\nKhong du bo nho de cap phat !!!";
	    return NULL;
	}
	p->data = x; // thÃªm giÃ¡ trá»‹ cá»§a biáº¿n x vÃ o trong data cá»§a cÃ¡i node
	p->pNext = NULL;
	return p;
}
bool QUEUE::IsEmpty(QUEUE q) // KIá»‚M TRA QUEUE CÃ“ Rá»–NG HAY KHÃ”NG
{
	if (q.pHead == NULL) // náº¿u danh sÃ¡ch rá»—ng
		return true;
	return false;// danh sÃ¡ch cÃ³ pháº§n tá»­
}	
bool QUEUE::Push(QUEUE &q, NODE *p){ // THÃŠM 1 PHáº¦N Tá»¬ VÃ€O CUá»I QUEUE- FIFO
	if (p == NULL)
		return false;
	if (IsEmpty(q) == true)	// náº¿u danh sÃ¡ch rá»—ng
	    q.pHead = q.pTail = p; // node p chÃ­nh lÃ  node Ä‘áº§u vÃ  node cuá»‘i
	else{ // danh sÃ¡ch Ä‘Ã£ cÃ³ pháº§n tá»­
		q.pTail->pNext = p; // liÃªn káº¿t con trá» cuá»‘i cá»§a danh sÃ¡ch vá»›i pháº§n tá»­ p cáº§n thÃªm vÃ o
		q.pTail = p; // cáº­p nháº­t láº¡i con trá» cuá»‘i lÃ  node p
	}
	return true;
}	
bool QUEUE::Pop(QUEUE &q, int &x){ // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y trong node
	if (IsEmpty(q) == true) // náº¿u danh sÃ¡ch rá»—ng
		return false;
	else{
		NODE *p = q.pHead; // node p chÃ­nh lÃ  node tháº¿ máº¡ng Ä‘á»ƒ tÃ­ ná»¯a chÃºng ta xÃ³a nÃ³ Ä‘i
		x = p->data; // gÃ¡n giÃ¡ trá»‹ cá»§a node Ä‘áº§u stack vÃ o biáº¿n x	
		q.pHead = q.pHead->pNext; // cáº­p nháº­t node Ä‘áº§u queue lÃ  node tiáº¿p theo	
		delete p; // xÃ³a node Ä‘áº§u queue vá»«a láº¥y 
	}
	return true;// láº¥y pháº§n tá»­ Ä‘áº§u queue thÃ nh cÃ´ng
}
bool QUEUE::Top(QUEUE &q, int &x){ // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem
	if (IsEmpty(q) == true)
		return false;
	x = q.pHead->data; // láº¥y giÃ¡ trá»‹ cá»§a pháº§n tá»­ Ä‘áº§u queue ra Ä‘á»ƒ xem
	return true;		
}
bool QUEUE::Back(QUEUE &q, int &x){ // x chÃ­nh lÃ  giÃ¡ trá»‹ cáº§n láº¥y ra Ä‘á»ƒ xem
	if (IsEmpty(q) == true)
		return false;
	else{	
	    x = q.pTail->data; // láº¥y giÃ¡ trá»‹ cá»§a pháº§n tá»­ Ä‘áº§u queue ra Ä‘á»ƒ xem
	    return true;
	}	
}
void QUEUE::XuatQueue(QUEUE q){ // hÃ m xuáº¥t danh sÃ¡ch queue
	while(IsEmpty(q) == false){
		int x;
		Pop(q, x);
		cout << x << " ";
	}
	        
}
void QUEUE::NhapQueue(QUEUE &q){// hÃ m nháº­p danh sÃ¡ch cÃ¡c sá»‘ nguyÃªn trong queue
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them vao queue - Push";
		cout << "\n\t2. Xuat danh sach phan tu sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t4. Xem thong tin phan tu cuoi queue - Back";
		cout << "\n\t5. Kiem tra queue co rong hay khong - Empty";
		cout << "\n\t6. Xoa thong tin phan tu dau queue - Pop";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1){
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
		}
		else if (luachon == 2){
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3){
			int x;
			Top(q, x);
			cout << "\nPhan tu dau queue la: " << x<<endl;
			system("pause");
		}
		else if (luachon == 4){
			int x;
			Back(q, x);
			cout << "\nPhan tu cuoi queue la: " << x;
			system("pause");
		}
		else if (luachon == 5){
			if(IsEmpty(q) == true)
		        cout << "\nDanh sach dang rong"<<endl;
	        else
		        cout << "\nDanh sach dang ton tai phan tu"<<endl;
			system("pause");	
		}
		else if (luachon == 6){
			int x;
		    Pop(q, x);
		}
		else
			break;
	}
}
int main()
{
	QUEUE q;
	q.KhoiTaoQueue(q);
	q.NhapQueue(q);

	system("pause");
	return 0;
}