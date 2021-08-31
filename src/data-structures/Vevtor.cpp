#include<iostream>
using namespace std;
#include<vector>
void xuat(vector<int>v){ 
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
}
int main(){
    vector<int>v; // khai bÃ¡o máº£ng vector
    vector<int>v1(10); // khai bÃ¡o vector cÃ³ 10 pháº§n tá»­
    vector<int>v2(10, 2); // khai bÃ¡o vector cÃ³ 10 pháº§n tá»­ vá»›i giÃ¡ trá»‹ khá»Ÿi táº¡o lÃ  2

    // khai bÃ¡o vector cÃ³ 10 pháº§n tá»­
    cout<<"\nKhai bao vector 1 co 10 phan tu";
    cout<<"\nVector 1: ";
    xuat(v1);

    // khai bÃ¡o vector cÃ³ 10 pháº§n tá»­ vá»›i giÃ¡ trá»‹ khá»Ÿi táº¡o lÃ  2
    cout<<"\nKhai bao vector 2 co 10 phan tu voi gia tri khoi tao la 2";
    cout<<"\nVector 2: ";
    xuat(v2);

    // thÃªm 10 pháº§n tá»­ vÃ o cuá»‘i máº£ng vector
    cout<<"\nThem 10 phan tu vao cuoi mang vector"<<endl;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    xuat(v);

    // tráº£ vá» pháº§n tá»­ Ä‘áº§u tiÃªn cá»§a máº£ng
    cout<<"Tra ve phan tu dau tien: ";
    cout<<v.front()<<endl;

    // tráº£ vá» pháº§n tá»­ cuá»‘i cÃ¹ng cá»§a máº£ng
    cout<<"Tra ve phan tu cuoi cung: ";
    cout<<v.back()<<endl;

    // ThÃªm pháº§n tá»­
    cout<<"\nThem phan tu vao vi tri thu 1 co gia tri = 69"<<endl;
    v.insert(v.begin() + 1, 69);
    xuat(v);
    cout<<"\nThem phan tu vao vi tri thu 2, 2 phan tu co gia tri = 339"<<endl;
    v.insert(v.begin() + 2, 2, 339);
    xuat(v);
    cout<<"\nThem vao phan tu cuoi cung"<<endl;
    v.insert(v.end(), 60);
    xuat(v);

    // xÃ³a pháº§n tá»­ cuá»‘i
    cout<<"\nXoa phan tu cuoi"<<endl;
    v.pop_back();
    xuat(v);

    // xÃ³a pháº§n tá»­ Ä‘áº§u
    cout<<"\nXoa phan tu dau"<<endl;
    v.erase(v.begin());
    xuat(v);
    
    // xÃ³a 2 pháº§n tá»­ cuá»‘i
    cout<<"\nXoa 2 phan tu cuoi"<<endl;
    v.erase(v.end() - 2, v.end());
    xuat(v);

    // xÃ³a háº¿t pháº§n tá»­ trong máº£ng
    cout<<"\nDa xoa het cac phan tu trong mang vector"<<endl;
    v.clear();
    xuat(v);
    
    // hoÃ¡n Ä‘á»•i 2 vector
    cout<<"Hoan doi 2 vector"<<endl;
    v.swap(v2);
    xuat(v);
     
    // kÃ­ch cá»¡ lá»›n nháº¥t mÃ  vector chá»©a Ä‘Æ°á»£c 
    cout<<"\nKich co hien tai vector luu tru: "<<v.capacity()<<endl;

    // kÃ­ch cá»¡ lá»›n nháº¥t mÃ  vector chá»©a Ä‘Æ°á»£c 
    cout<<"\nKich co lon nhat cua vector: "<<v.max_size()<<endl;

    return 0;
}
   