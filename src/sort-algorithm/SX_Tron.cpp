#include <iostream>

using namespace std;





int main()
{
	int n, i;
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;
	
	for (i = 0; i <= n; i++)
	{
		cout<<"\nNhap phan tu thu "<<i + 1<<": ";
		cin >> a[i];
	}
	merge_sort(1, n);
	cout << "Mang sau khi duoc sap xep:" << endl;

	for (i = 0; i <= n; i++)
	{
        cout << a[i] << "  ";
	}
		

	system("pause");
	return 0;
}