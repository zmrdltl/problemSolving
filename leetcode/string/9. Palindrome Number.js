/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    x = x.toString();
    for(let i  =0; i < x.length/2; i++){
        if(x[i]!==x[x.length-1-i])return false;
    }
  return true;  
};