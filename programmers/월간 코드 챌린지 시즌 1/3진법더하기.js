function solution(n) {
    let num3 = parseInt(n).toString(3)
    let reversedNum3 = ""
    for(let i = num3.length-1; i >= 0; i--){
        reversedNum3 += num3[i]
    }

    return  parseInt(reversedNum3,3);
}
console.log(solution(45))