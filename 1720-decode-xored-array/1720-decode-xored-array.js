/**
 * @param {number[]} encoded
 * @param {number} first
 * @return {number[]}
 */
var decode = function(encoded, first) {
    let arr = [first]
    const n = encoded.length + 1;
    for( let i = 1 ; i < n ; i++){
        arr[i] = arr[i-1]^encoded[i-1];
    }
    
    return arr;
};