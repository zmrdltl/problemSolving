function getDollPos(board,oneMove){
    for(let i = 0; i < board[0].length; i++){
        if(board[i][oneMove]) return i;
    }
    return -1;
}
function updateDollState(doll){
    for(let i = 0; i < doll.length - 1; i++){
        if(doll[i] === doll[i+1] && doll[i]){
            doll.pop()
            doll.pop()
            return 1;
        }
    }
    return 0;   
}
function solution(board, moves) {
    let answer = 0;
    let doll = [];
    for(let i = 0; i < moves.length; i++){
        const pos = getDollPos(board,moves[i]-1);
        if(pos!==-1){
            doll.push(board[pos][moves[i]-1]);
            board[pos][moves[i]-1] = 0;
            if(updateDollState(doll)){
                answer += 2;
            }
        }
    }
    return answer;
}
console.log(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],[1,5,3,5,1,2,1,4]))