﻿#include<iostream>
#include<string>
using namespace std;
class SINHVIEN
{
	private:
		string HoTen;
		string MSSV;
		SINHVIEN *pNext;
        SINHVIEN *pPrev;
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
		void ThemDau(LIST &l, SINHVIEN *p); // hàm thêm 1 cái Sinh Viên vào đầu danh sách     
		void ThemCuoi(LIST &l, SINHVIEN *p);
		void XoaDau(LIST &l); // hàm xóa đầu
		void XoaCuoi(LIST &l); // xóa cuối
		void OutPut(LIST l); // hàm xuất danh sách liên kết đơn
		void InPut_List(LIST &l); // hàm menu			
};
void LIST::KhoiTaoDanhSach(LIST &l){ 
	l.pHead = NULL;
	l.pTail = NULL; 
}
SINHVIEN* LIST::KhoiTaoSinhVien(string HoTen, string MSSV){ // hàm khởi tạo 1 cái Sinh Viên để chuẩn bị thêm vào danh sách
	SINHVIEN *p = new SINHVIEN;
	if (p == NULL){
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->HoTen = HoTen; 
	p->MSSV = MSSV;;
	p->pNext = NULL;
    p->pPrev = NULL; 
	return p;
}
void LIST::ThemDau(LIST &l, SINHVIEN *p){ 		
	if (l.pHead == NULL){ 
	    l.pHead = l.pTail = p; 
	}
	else{
		p->pNext = l.pHead; 
	    l.pHead = p;
        p->pNext->pPrev = p; 
	}
} 
void LIST::ThemCuoi(LIST &l, SINHVIEN *p){ 

	if (l.pHead == NULL){
		l.pHead = l.pTail = p; 
	}
	else{
		l.pTail->pNext = p; 
        p->pPrev = l.pTail; 
        l.pTail = p; 
	}
} 
void LIST::XoaDau(LIST &l){ 

	if (l.pHead == NULL) 
		return;
	SINHVIEN *p = l.pHead; 
	l.pHead = l.pHead->pNext;
    l.pHead->pPrev = NULL;
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
			SINHVIEN *p = l.pTail;
                        l.pTail->pPrev->pNext = NULL;
                        l.pTail = l.pTail->pPrev;
                        delete p;
		}
	}
}
void LIST::OutPut(LIST l){ 
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		cout<<"\nHo ten: "<<k->HoTen<<endl;
		cout<<"\nMSSS: "<<k->MSSV<<endl;
	}		

}
void LIST::InPut_List(LIST &l){ 
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t ================ MENU ==============";
		cout << "\n1. Them Dau";
		cout << "\n2. Them Cuoi";
        cout << "\n3. Xuat danh sach";
		cout << "\n4. Xoa Dau";
		cout << "\n5. Xoa Cuoi";
        cout << "\n0. Thoat";
		cout << "\n\n\t\t ================ END ===============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1){
			string HoTen;
			string MSSV;
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien: ";
			getline(cin, HoTen);
			cout<<"Nhap MSSV: ";
			getline(cin, MSSV);
			SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
			ThemDau(l, p);
		}
		else if (luachon == 2){	
			string HoTen;
			string MSSV;
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien: ";
			getline(cin, HoTen);
			cout<<"Nhap MSSV: ";
		    getline(cin, MSSV);
			SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
			ThemCuoi(l, p);
		}
        else if (luachon == 3){
			cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
			OutPut(l);
			system("pause");
		}
		else if (luachon == 4){
			XoaDau(l);
		}
		else if (luachon == 5){
			XoaCuoi(l);
		}
		else
		{
			break;
		}
	}
}           											     		   
int main(){
	LIST l;
	l.KhoiTaoDanhSach(l);
	l.InPut_List(l);

	system("pause");		
	return 0;
}       