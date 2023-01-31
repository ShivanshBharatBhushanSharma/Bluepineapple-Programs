#include <iostream>
using namespace std;

bool getPalindrome(char* word){
    int i=0;
    int j=-1;

    bool flag = true;
    while(i<j){
        if(word[i]!=word[j]) flag = false;
        i++;
        j--;
    }
    return flag;
}

void testCase(bool actual_Result,bool expected_Result,char* word){
    
    if(actual_Result == expected_Result){
        std::cout<<"Test Case Successful for "<<word<<"\n";    
    }else {
        std::cout<<"Test Case Failed for "<<word<<"\n";
    } 
}

int main() {
    
    int i,j;
    char* actual_Word[]={"MOM","Lotus","MALAYALAM","Ram","LOl","blue","shiv","madam","S","Delhi"};
    bool expected_Result[10]={true,false,true,false,true,false,false,true,true,false};
        
    bool actual_Result[10];
    
    for(i=0; i<10; i++){
        actual_Result[i] = getPalindrome(actual_Word[i]);
    }
    
    for(i=0; i<10; i++){
        testCase(actual_Result[i],expected_Result[i],actual_Word[i]);
    }    
    
    return 0;
}