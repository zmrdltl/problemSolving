function getPosition(keyPad,oneNum){
    for(let i = 0; i < keyPad.length; i++){
        for(let j = 0; j < keyPad[0].length; j++){
            if(keyPad[i][j]===oneNum){
                return [i,j];
            }
        }
    }
}

function solution(numbers, hand) {
    let answer = '';
    const keyPad = [
        [1,2,3],
        [4,5,6],
        [7,8,9],
        ['*',0,'#']
    ]

    let currentLeftPos = [3,0];
    let currentRightPos = [3,2];
    for(let i = 0; i < numbers.length; i++){
        
        const numPos = getPosition(keyPad,numbers[i]);

        const leftX = currentLeftPos[0] - numPos[0];
        const leftY = currentLeftPos[1] - numPos[1];
        const rightX = currentRightPos[0] - numPos[0];
        const rightY = currentRightPos[1] - numPos[1];

        const distanceFromLeft =  Math.abs(leftX) + Math.abs(leftY);
        const distanceFromRight =  Math.abs(rightX) + Math.abs(rightY);
        
        if(numbers[i]===1 ||numbers[i]===4 ||numbers[i]===7){
            answer +="L"
            currentLeftPos = numPos;
            continue;  
        }

        if(numbers[i]===3 ||numbers[i]===6 ||numbers[i]===9)
        {
            answer +="R"
            currentRightPos = numPos;
            continue;  
        }

        if(distanceFromLeft===distanceFromRight){
            if(hand==="right"){
                answer+="R"
                currentRightPos = numPos;
            }
            else{
                answer+="L"
                currentLeftPos = numPos;
            }
            continue;
        }

        if(distanceFromLeft > distanceFromRight){
            answer += 'R'
            currentRightPos = numPos;
            continue;
        }

        if(distanceFromLeft < distanceFromRight){
            answer += 'L'
            currentLeftPos = numPos;
            continue;
        }
    }

    return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5],"right"))