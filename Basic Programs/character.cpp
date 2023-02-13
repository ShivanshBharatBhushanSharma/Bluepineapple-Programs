#include<iostream>
using namespace std;

void checkChar(char chr){
    int unicode=int(chr);
    
    if( (unicode>=65 && unicode<=90) || 
    (unicode>=97 && unicode<=122) )
    {
        std::cout<<"It is a character";
    }
    else
    {
        std::cout<<"It is not a character";
    }
}
int main() {
    char chr;
    
    std::cout<<"Enter Character to check char or not = ";
    std::cin>>chr;
    
    checkChar(chr);
    
    return 0;
}