function checkLeapDay( dd, mm, yyyy)
{  
    if((yyyy%4==0 && yyyy%100!=0) || yyyy%400==0)
    {
        if(dd==29 && mm==2)
        {
            return 1;
        }   
    }
    else
    {
        return 0;
    }
}

let actualNumber = [
[29,02,1999],
[29,02,2000],
[29,02,2005],
[29,02,2012],
[29,02,2022],
[29,02,2024]
];

let actualOutput = [0,1,0,1,0,1];
let predictedOutput = [];

for(let i=0; i<actualNumber.length; i++){
let date = actualNumber[i][0];
let month = actualNumber[i][1];
let year = actualNumber[i][2];

predictedOutput[i] = checkLeapDay(date, month, year);
}
   
for(let i=0; i<actualNumber.length; i++){
    if(actualOutput[i] === predictedOutput[i]){
        console.log(`Test case for ${actualNumber[i][0]}/${actualNumber[i][1]}/${actualNumber[i][2]} is passed.`);
    } else {
        console.log(`Test case for ${actualNumber[i][0]}/${actualNumber[i][1]}/${actualNumber[i][2]} is failed.`);
    }
}