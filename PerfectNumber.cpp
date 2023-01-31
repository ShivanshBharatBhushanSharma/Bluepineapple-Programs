#include <iostream>
using namespace std;

int perfectNumber(int num){
    int sum_Factor = 0;
    for(int i=1;i<num;i++){
        if(num % i == 0)
            sum_Factor += i;
    }
    if (sum_Factor == num) return num;
    return 0;
}

void testCase(int actualPerfectNumber,int expectedPerfectNumber){
    if(actualPerfectNumber == expectedPerfectNumber){
      std::cout<<"Test Case Successfull for "<<actualPerfectNumber<<"\n";
    } else {
        std::cout<<"Test Case Failed for "<<actualPerfectNumber<<"\n";
    } 
}

int main() {
    
    int i,j;
    int n=10000;
    int expectedPerfectNumber[]={6,28,496,8128};
    int actualPerfectNumber = 0;
    
    std::cout<<"Perfect Number upto "<<n<<"\n";
    
    for(i=1,j=0;i<=n,j<4;i++){
        actualPerfectNumber = perfectNumber(i);
        
        if(actualPerfectNumber) {
        testCase(actualPerfectNumber,expectedPerfectNumber[j]);
        j++;        
        }    
    
    }
    return 0;
}