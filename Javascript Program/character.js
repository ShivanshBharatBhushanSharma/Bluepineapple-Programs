function character(item){
    if(item >= 'A' && item <= 'Z' || item >= 'a' && item <= 'z') {
            return 1;
        } else {
            return 0;
        }
}

function TestCase(actualOutput, predictedOutput){
    
    for(let i = 0; i < arr.length ; i++) {
        if(actualOutput[i] === predictedOutput[i])
        {
            console.log(`Test Case for ${arr[i]} is passed.`);
        }
        else
        {
            console.log(`Test Case for ${arr[i]} is Failed.`);
        }
    }    
}

var arr = [ 'A', '#', 3, 'a', '*' ];
var actualOutput = [ 1, 0, 0, 1, 0 ];
var predictedOutput = [];
let counter = 0;

arr.forEach(function(item , index, arr){        
    predictedOutput[counter++] = character(item);
});

TestCase(actualOutput, predictedOutput);

