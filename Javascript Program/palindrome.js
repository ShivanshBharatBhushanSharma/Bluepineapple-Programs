function palindrome(item){
       var i = 0;
       var j = item.length - 1;
       var flag = 1;
        while(i < j){
            if( item[i] != item[j] ){
                flag = 0;
                break;
            }
            i++;
            j--;    
        }
        return flag; 
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

var arr = [ 'MADAM', 'WOW', 'Blue', 'MALAYALAM', 'Shivansh']; 
var actualOutput = [ 1, 1, 0, 1, 0 ];
var predictedOutput = [ ];
let counter = 0;

arr.forEach(item => {
    predictedOutput[counter++] = palindrome(item);
});

TestCase(actualOutput, predictedOutput);
