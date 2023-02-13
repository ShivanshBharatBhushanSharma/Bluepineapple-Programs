function countDigitOccurence(num){
    let digitsCount = [0,0,0,0,0,0,0,0,0,0];

    while(num != 0){
        let rem = Math.trunc(num % 10);

        switch(rem){
            case 0: digitsCount[0] += 1;
                    break;
            case 1: digitsCount[1] += 1;
                    break;
            case 2: digitsCount[2] += 1;
                    break;
            case 3: digitsCount[3] += 1;
                    break;
            case 4: digitsCount[4] += 1;
                    break;
            case 5: digitsCount[5] += 1;
                    break;
            case 6: digitsCount[6] += 1;
                    break;
            case 7: digitsCount[7] += 1;
                    break;
            case 8: digitsCount[8] += 1;
                    break;
            case 9: digitsCount[9] += 1;
                    break;
        }
        num = Math.trunc(num / 10);
    }
    return digitsCount;
}

let actualNumber = [1231,0320123,453245,1343132,467001,123456789,235676871];
let actualOutput = [
      [
        0, 2, 1, 1, 0, 0, 0, 0, 0, 0
      ],
      [
        1, 1, 0, 0, 0, 1, 1, 1, 0, 1
      ],
      [
        0, 0, 1, 1, 2, 2, 0, 0, 0, 0
      ],
      [
        0, 2, 1, 3, 1, 0, 0, 0, 0, 0
      ],
      [
        2, 1, 0, 0, 1, 0, 1, 1, 0, 0
      ],
      [
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1
      ],
      [
        0, 1, 1, 1, 0, 1, 2, 2, 1, 0
      ]

];
let predictedOutput = [];
let size = 0;

actualNumber.forEach(function (number){
    predictedOutput[size++] = countDigitOccurence(number);
});

for(let i = 0; i < actualNumber.length; i++){
    if( actualOutput[i][0] == predictedOutput[i][0] &&
        actualOutput[i][1] == predictedOutput[i][1] &&
        actualOutput[i][2] == predictedOutput[i][2] &&
        actualOutput[i][3] == predictedOutput[i][3] &&
        actualOutput[i][4] == predictedOutput[i][4] &&
        actualOutput[i][5] == predictedOutput[i][5] &&
        actualOutput[i][6] == predictedOutput[i][6] &&
        actualOutput[i][7] == predictedOutput[i][7] &&
        actualOutput[i][8] == predictedOutput[i][8] &&
        actualOutput[i][9] == predictedOutput[i][9] ) {
        console.log(`Test case for ${actualNumber[i]} is passed.`);
    } else {
        console.log(`Test case for ${actualNumber[i]} is failed.`);
    }
}