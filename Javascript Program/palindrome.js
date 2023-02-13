function palindrome(arr){
    arr.forEach(item => {
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
        (flag) ? console.log(`${item} is Palindrome.`) : console.log(`${item} is not Palindrome.`); 
    });
}
let arr = [ 'MADAM', 'WOW', 'Blue', 'MALAYALAM', 'Shivansh']; 
palindrome(arr);