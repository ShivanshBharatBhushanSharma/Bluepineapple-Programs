function digitCount(n)
{
    let count=0;
    
    if(n == 0) return 1; 
    while(Math.trunc(n))
    {
        n=n/10;
        count++;
    }
    return count;
}

let actualNumber = [0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000];
let actualOutput = [1,2,3,4,5,6,7,8,9,10];
let predictedOutput = [];
let size = 0;

actualNumber.forEach(function (value){
    predictedOutput[size++] = digitCount(value);
});

for(let i = 0; i < actualNumber.length; i++){
    if(actualOutput[i] === predictedOutput[i]){
        console.log(`Test case for ${actualNumber[i]} is passed.`);
    } else {
        console.log(`Test case for ${actualNumber[i]} is failed.`);
    }
}

