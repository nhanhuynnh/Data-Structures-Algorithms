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
void QuickSort(int a[], int Left, int Right){
	if(Left >= Right)
	    return;
	int pivot = a[(Left + Right)/2];
	int i = Left, j = Right;
	do{
		while(a[i] < pivot)
		    i++;
		while(a[j] > pivot)
		    j--;	
		if(i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}	
	}while(i < j);	
	QuickSort(a, Left, j);
	QuickSort(a, i, Right);
}
void Xuat(int a[], int n){
	for(int i = 0; i < n; i++){
	cout<<a[i]<<"  ";
	}
}
int main(){
	int a[100];
	int n, Left, Right;
	Nhap(a, n);
	cout<<"\nMang ban dau: ";
	Xuat(a, n);
	QuickSort(a, 0, n - 1);
	cout<<"\nMang sau khi Quick Sort: ";
	Xuat(a, n);
	system("pause");
	return 0;
}