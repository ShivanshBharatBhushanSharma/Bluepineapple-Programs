function perfectNumber(num){
    var sum_Factor = 0;
    for(let i = 1; i < num; i++){
        if(num % i == 0)
            sum_Factor += i;
    }
    if (sum_Factor == num) console.log(`${num}`);
}

let upto_number = 1000;
console.log(`Perfect Number upto ${upto_number} -`);

for(let i = 2; i <= upto_number; i++) perfectNumber(i);