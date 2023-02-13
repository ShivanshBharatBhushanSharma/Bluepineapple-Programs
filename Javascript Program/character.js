function character(arr){
    arr.forEach(function(item , index, arr){
        if(item >= 'A' && item <= 'Z' || item >= 'a' && item <= 'z') {
            console.log(`${item} is a character.`);
        } else {
            console.log(`${item} is not a character.`);
        }
    });
}
var arr = [ 'A', '#', 3, 'a', '*' ];
character(arr);