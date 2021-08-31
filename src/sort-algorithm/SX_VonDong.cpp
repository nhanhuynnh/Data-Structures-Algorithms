#include<iostream>
using namespace std;
#include<conio.h>
// nhap day
void NhapMang(int A[],int n) 
{
 	for(int i=0; i<n; i++) 
 	{
  		cout<<"nhap Phan tu thu A["<<i<<"] =";
  		cin>>A[i];
 	}
}
// in day
void XuatMang(int A[],int n) 
{
 	cout<<endl;
 	for(int i=0; i<n; i++)
  	cout<<A[i]<<"\t";
}
// doi cho 2 so
void Swap(int &a,int &b) 
{
 	int temp = a;
 	a = b;
 	b = temp;
}
//hoan vi nut cha thu i phai lon hon nut con (vun dong)
void Heapify(int A[],int n, int i) 
{
 int Left = 2*(i+1)-1;
 int Right = 2*(i+1);
 int Largest;
 if(Left<n && A[Left]>A[i])
  Largest = Left;
 else
  Largest = i;
 if(Right<n && A[Right]>A[Largest])
  Largest = Right;
 if(i!=Largest) 
  {
    Swap(A[i],A[Largest]);
    Heapify(A,n,Largest);
  }
}
//xay dung Heap sao cho moi nut cha luon lon hon nut con tren cay (tao cay)
void BuildHeap(int A[], int n) 
{
  for(int i = n/2-1; i>=0; i--)
  Heapify(A,n,i);
}
// heap-sort
void HeapSort(int A[], int n) 
{
  BuildHeap(A,n);
  for(int i = n-1; i>0; i--)
  {
    Swap(A[0],A[i]);
    Heapify(A,i,0);
  }
}
// ham main
int main() 
{
	int n;
    int A[100];
 //clrscr();
 cout<<"Nhap so phan tu:";
 cin>>n;
 NhapMang(A,n);
 cout<<"\nMang vua nhap la:";
 XuatMang(A,n);
 cout<<"\nSap xep theo Heap Sort:";
 HeapSort(A,n);
 XuatMang(A,n);
 getch();
}