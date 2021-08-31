#include<iostream>
using namespace std;
#include<queue>

int main(){
    queue<int>q;
    // ThÃªm vÃ o cuá»‘i
    q.push(8); 
    q.push(9);
    q.push(1);
    q.push(3);
    q.push(2);

    // Láº¥y ra pháº§n tá»­ Ä‘áº§u
    cout<<"Phan tu dau tien: "<<q.front()<<endl;
    
    // Láº¥y ra pháº§n tá»­ cuá»‘i cÃ¹ng
    cout<<"Phan tu cuoi cung: "<<q.back()<<endl;

    // Pháº§n tá»­ Ä‘áº§u tiÃªn sau khi pop
    q.pop();
    cout<<"Phan tu dau tien sau khi pop: "<<q.front()<<endl;

    // kiá»ƒm tra stack cÃ³ rá»—ng hay khÃ´ng
    cout<<"Stack rong hay khong(0 la 0 rong, 1 la rong): "<<q.empty()<<endl;
    
    // kÃ­ch thÆ°á»›c cá»§a queue
    cout<<"Kich thuoc hien tai queue dang luu tru: ";
    cout<<q.size()<<endl;

    
    return 0;
}