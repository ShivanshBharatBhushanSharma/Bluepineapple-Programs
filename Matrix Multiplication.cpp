#include <iostream>
using namespace std;

int i,j,k;
const int m=2;
const int n=2;
int actual_Result[2][2];
    
void getMatrixMultiplication(int Matrix1[m][n],int Matrix2[m][n]){
    for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                actual_Result[i][j] = 0;
                for (k = 0; k < n; k++) {
                    actual_Result[i][j] += Matrix1[i][k] * Matrix2[k][j];
                }
            }
        }
}

void testCase(int actual_Result[m][n],int expected_Result[m][n]){
    bool flag = false;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(actual_Result[i][j] == expected_Result[i][j])
            flag = true;
        }
    }
    if(flag){
        std::cout<<"Test Case Successful for Matrix"<<"\n";    
    }else {
        std::cout<<"Test Case Failed for Matrix"<<"\n";
    } 
}

int main() {
    
    int matrix1[m][n]={{1,2},{3,4}};
    int matrix2[m][n]={{1,2},{3,4}};
    int expected_Result[m][n]={7,10,15,22};
        
    std::cout<<"Matrix 1:"<<"\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            std::cout<<matrix1[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"Matrix 2:"<<"\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            std::cout<<matrix2[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
    getMatrixMultiplication(matrix1,matrix2);
    
    testCase(actual_Result,expected_Result);
    
    return 0;
}