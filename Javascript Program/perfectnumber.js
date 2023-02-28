function perfectNumber(num){
    var sum_Factor = 0;
    for(let i = 1; i < num; i++){
        if(num % i == 0)
            sum_Factor += i;
    }
    if (sum_Factor == num) return num;
}

function TestCase(actualOutput, predictedOutput){
    
    for(let i = 0; i < actualOutput.length ; i++) {
        if(actualOutput[i] === predictedOutput[i])
        {
            console.log(`Test Case for ${predictedOutput[i]} is passed.`);
        }
        else
        {
            console.log(`Test Case for ${predictedOutput[i]} is Failed.`);
        }
    }    
}

let upto_number = 1000;
let actualOutput = [6, 28, 496 ];
let predictedOutput = [];
let counter = 0;

console.log(`Perfect Number upto ${upto_number} -`);

for(let i = 2; i <= upto_number; i++){
    let value = perfectNumber(i);
    if(value) predictedOutput[counter++] = value;
}

TestCase(actualOutput, predictedOutput);
