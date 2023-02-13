let i, j, k;
let m = 2, n = 2;
var actual_Result = [ [0,0], [0,0] ];

function getMatrixMultiplication(){
    for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                actual_Result[i][j] = 0;
                for (k = 0; k < n; k++) {
                    actual_Result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
}

var matrix1 = [ [1,2], [3,4] ];
var matrix2 = [ [1,2], [3,4] ];
        
console.log("Matrix 1:");
matrix1.forEach(item => {
    console.log(item);
});
    
console.log("Matrix 2:");
matrix2.forEach(item => {
    console.log(item);
});
    
getMatrixMultiplication();

console.log("Matrix Multiplication:");
actual_Result.forEach(item => {
    console.log(item);
});