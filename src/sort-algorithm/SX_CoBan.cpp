#include<iostream>
using namespace std;
void Nhap(int a[], int &n){
	cout<<"\nNhap vao n: ";
	cin>>n;
	for(int i = 0; i < n; i++){
		cout<<"\nPhan tu thu "<<i + 1<<": ";
		cin>>a[i];
	}
}
void SXNoiBot(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				int tg = a[j];
				a[j] = a[j-1];
				a[j-1] = tg;
			}
		}
	}
}
void Xuat(int a[], int n){
	for(int i = 0; i < n; i++){
	cout<<a[i]<<"  ";
	}
}
int main(){
	int a[100];
	int n;
    Nhap(a,n);
	SXNoiBot(a, n);
	Xuat(a,n);

    system("pause");
	return 0;
}