#include<iostream>
using namespace std;
#include<stack>

int main(){
    stack<int>s;
    
    // ThÃªm vÃ o Ä‘áº§u
    s.push(6);
    s.push(3);
    s.push(8);
    s.push(1);
    s.push(7);

    // Láº¥y ra pháº§n tá»­ Ä‘áº§u tiÃªn
    cout<<"Phan tu dau tien: "<<s.top()<<endl;
    
    // XÃ³a pháº§n tá»­ Ä‘áº§u tiÃªn
    s.pop();
    cout<<"Phan tu dau tien sau khi pop: "<<s.top();

    // kiá»ƒm tra stack cÃ³ rá»—ng hay khÃ´ng
    cout<<"\nStack rong hay khong(0 la 0 rong, 1 la rong): "<<s.empty()<<endl;

    // kÃ­ch thÆ°á»›c cá»§a stack
    cout<<"Kich thuoc hien tai stack dang luu tru: ";
    cout<<s.size()<<endl;

    return 0;
}