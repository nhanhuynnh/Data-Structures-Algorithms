
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int UT(char c){ // Tráº£ vá» má»©c Ä‘á»™ Æ°u tiÃªn cá»§a cÃ¡c toÃ¡n tá»­
    if(c == '(')
       return 0;
    if(c == '+' || c == '-')
       return 1;
    if(c == '*' || c == '/' || c == '%')
       return 2;
    if(c == '^')
       return 3; 
}
void HauTo(){ // Chuyá»ƒn biá»ƒu thá»©c trung tá»‘ sang háº­u tá»‘
    stack<char>s;
    int i = 0;
    string str, str1 = "";
    getline(cin, str);
    while (i < str.length()){
        char c = str.at(i);
        if(c != ' '){
            if(c - '0' >= 0 && c - '0' <= 9 || isalpha(c))
                str1 = str1 + c;
            else{
                cout<<str1<<" ";
                str1 = "";
                if(c =='(')
                    s.push(c);
                else{
                    if(c == ')'){
                        while (s.top() != '(')
                        {
                            cout<<s.top();
                            s.pop();
                        }
                        s.pop();
                    }    
                    else
                    {
                        while (!s.empty() && UT(c) <= UT(s.top()))
                        {
                            cout<<s.top();
                            s.pop();
                        }
                        s.push(c);  
                    } 
                }   
            } 
        }
        i++;
    }
    if(str1 != ""){
        cout<<str1<<" ";
    } 
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }    
}
int main(){
	cout<<"Nhap bieu thuc can tinh: "<<endl;
    HauTo();

    return 0;
}