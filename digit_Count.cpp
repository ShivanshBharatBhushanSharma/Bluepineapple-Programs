#include <iostream>
using namespace std;

int countDigit(int num){
    int count=0;
    if(num>9)
    {
        while(num){
        count++;
        num/=10;
        }
        return count;
    }
    else{
        return 1;
    }
    
}
void testCase(int num){
    int number=num;
    num=abs(num);
    if((num>=0 && num<=9) && (countDigit(num) == 1))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=10 && num<=99) && (countDigit(num) == 2))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=100 && num<=999) && (countDigit(num) == 3))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=1000 && num<=9999) && (countDigit(num) == 4))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=10000 && num<=99999) && (countDigit(num) == 5))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=100000 && num<=999999) && (countDigit(num) == 6))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=1000000 && num<=9999999) && (countDigit(num) == 7))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=10000000 && num<=99999999) && (countDigit(num) == 8))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=100000000 && num<=999999999) && (countDigit(num) == 9))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else if((num>=1000000000 && num<=2147483647) && (countDigit(num) == 10))
    {
        std::cout<<"Test case for "<<number<<" passed"<<"\n";
    }
    else{
        std::cout<<"Test case for "<<number<<" failed as number exceeded than 10 digit"<<"\n";
    }
    
}
int main() {
    
    int num[]={0,10,-100,1000,10000,-100000,1000000,-10000000,100000000,-1000000000};
    //std::cout<<sizeof(num);
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++) 
        testCase(num[i]);
    return 0;
}