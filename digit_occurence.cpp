#include <iostream>
using namespace std;
    
int* countDigitOccurence(int num){
    int temp_num = num;
    int occurence_of_digit[10] = {0,0,0,0,0,0,0,0,0,0};

    while(temp_num){
        int last_digit = temp_num%10;
        switch(last_digit){
            case 0 : occurence_of_digit[0] += 1; break;
            case 1 : occurence_of_digit[1] += 1; break;
            case 2 : occurence_of_digit[2] += 1; break;
            case 3 : occurence_of_digit[3] += 1; break;
            case 4 : occurence_of_digit[4] += 1; break;
            case 5 : occurence_of_digit[5] += 1; break;
            case 6 : occurence_of_digit[6] += 1; break;
            case 7 : occurence_of_digit[7] += 1; break;
            case 8 : occurence_of_digit[8] += 1; break;
            case 9 : occurence_of_digit[9] += 1; break;
        }
        temp_num /= 10;
    }
    return occurence_of_digit;
}

void testCase(int* actual_Occurence,int* expected_Occurence, int actual_Number){
    int flag = 1;
    for(int i=0;i<10;i++){
        if(actual_Occurence[i] != expected_Occurence[i]){
            flag = 0;
            break;
        }    
    }
    if(flag){
      std::cout<<"Test Case Successfull for "<<actual_Number<<"\n";
    } else {
        std::cout<<"Test Case Failed for "<<actual_Number<<"\n";
    } 
}

int main() {
    
    int i,j;
    int actual_Number[10]={10,122,112233,1234,45455,6787843,35487345,90909013,123890678,43655809};
    int expected_Occurence[10][10]={
        {1,1,0,0,0,0,0,0,0,0},
        {0,1,2,0,0,0,0,0,0,0},
        {0,2,2,2,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,2,3,0,0,0,0},
        {0,0,0,1,1,0,1,2,2,0},
        {0,0,0,2,2,2,0,1,1,0},
        {3,1,0,1,0,0,0,0,0,3},
        {1,1,1,1,0,0,1,1,2,1},
        {1,0,0,1,1,2,0,0,1,1}
    };
    int* actual_Occurence[10];
    
    for(i=0;i<10;i++){
        actual_Occurence[i] = countDigitOccurence(actual_Number[i]);
    }    
    for(i=0; i<10; i++){
        // testCase(actual_Occurence[i],expected_Occurence[i],actual_Number[i]);
        // for(j=0; j<10; j++){
            std::cout<<actual_Occurence[i][j]<<" ";    
        // }
        std::cout<<"\n";
    }    
    
    return 0;
}