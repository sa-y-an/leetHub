/**
 * @param {string} s
 * @return {boolean}
 */
var areNumbersAscending = function(s) {
    let words = s.split(" ");
    let prev = 0;
    
    for( let i = 0 ; i  < words.length ; i++){
        if( words[i][0] >= '0' && words[i][0] <= '9' ){
            let temp = parseInt(words[i]);
            if( prev >= temp ) return false;
            prev = temp;
        }    
    }
    
    return true;
    
};