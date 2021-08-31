#include<iostream>
#include<string>
using namespace std;
class SINHVIEN
{
	private:
		string HoTen;
		string MSSV;
		SINHVIEN *pNext;
	public:
		friend class LIST;				
};		
class LIST
{
	private:
		SINHVIEN *pHead;
		SINHVIEN *pTail;
	public:		
		void KhoiTaoDanhSach(LIST &l);
		SINHVIEN *KhoiTaoSinhVien(string HoTen, string MSSV); 
		void ThemDau(LIST &l, SINHVIEN *p);  
		void ThemCuoi(LIST &l, SINHVIEN *p);
		void XoaDau(LIST &l); 
		void XoaCuoi(LIST &l); 
		void Edit(LIST &l, SINHVIEN *p);
		void OutPut(LIST l); 
		void Menu(LIST &l);		
};
void LIST::KhoiTaoDanhSach(LIST &l){ 
	l.pHead = NULL;
	l.pTail = NULL; 
}
SINHVIEN* LIST::KhoiTaoSinhVien(string HoTen, string MSSV){ 

	SINHVIEN *p = new SINHVIEN;
	p->HoTen = HoTen; 
	p->MSSV = MSSV;;
	p->pNext = NULL; 
	return p;
}
void LIST::ThemDau(LIST &l, SINHVIEN *p){ 	
	if (l.pHead == NULL){ 
	    l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead; 
		l.pHead = p; 
	}
} 
void LIST::ThemCuoi(LIST &l, SINHVIEN *p){ 

	if (l.pHead == NULL){
		l.pHead = l.pTail = p; 
	}
	else{
		l.pTail->pNext = p;
		l.pTail = p; 
	}
} 
void LIST::XoaDau(LIST &l){ 

	if (l.pHead == NULL) 
		return;
	SINHVIEN *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void LIST::XoaCuoi(LIST &l){ 

	if (l.pHead == NULL)
		return;
	if (l.pHead->pNext == NULL){ 
		XoaDau(l);
		return;
	}
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		if (k->pNext == l.pTail){ 
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k; 
			return;
		}
	}
}

void LIST::Edit(LIST &l, SINHVIEN *p){	
	string ten;
	cin.ignore();
	cout<<"\nNhap vao so can thay doi: ";
	getline(cin, ten);
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){
		if(ten == k->HoTen){
		    cout << "\nNhap gia tri: ";
			cin >>p->HoTen;
			k->HoTen = p->HoTen;	
		}		
	}
	 
}
void LIST::OutPut(LIST l){ 
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		cout<<"\nHo ten: "<<k->HoTen<<endl;
		cout<<"\nMSSS: "<<k->MSSV<<endl;
	}		
}
void LIST::Menu(LIST &l){ 
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Them Sinh Vien vao dau danh sach";
		cout << "\n2. Them Sinh Vien vao cuoi danh sach";	
        cout << "\n3. Thay doi thong tin Sinh Vien";
		cout << "\n4. Xuat danh sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =========== END ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
        switch(luachon)
        {
            case 1:
            {
                string HoTen;
                string MSSV;
                fflush(stdin);
                cout<<"Nhap ho ten sinh vien: ";
                getline(cin, HoTen);
                cout<<"Nhap MSSV: ";
                getline(cin, MSSV);
                SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
                ThemDau(l, p);
                break;
            }
            case 2:
            {
                string HoTen;
                string MSSV;
                fflush(stdin);
                cout<<"Nhap ho ten sinh vien: ";
                getline(cin, HoTen);
                cout<<"Nhap MSSV: ";
                getline(cin, MSSV);
                SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
                ThemCuoi(l, p);
			    system("pause");
                break;
            }    
            case 3:
            {
                SINHVIEN *p = new SINHVIEN;
			    Edit(l, p);
                break;
            }
            case 4:
            {
                cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
                OutPut(l);
                system("pause");
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout<<"\nLua chon khong hop le. Xin vui long kiem tra lai!!!"<<endl;
                system("pause");
                break;
            }

        }
    }while(luachon != 0);   
}        											     		   
int main(){
	LIST l;
	l.KhoiTaoDanhSach(l);
	l.Menu(l);

	system("pause");		
	return 0;
} 