/**
 * @param {number} n
 * @return {string[]}
 * 미완성
 */
const f = (n) => {
  const brackets = [];

  const dfs = () => {
    if (n / 2) {
      brackets.push(ans.slice(0));
    }
    for (let i = 0; i < n / 2; i++) {}
  };

  const makeList = (n) => {
    for (let i = 0; i < n / 2; i++)
      if (i < n / 2) {
        brackets.push("(");
      } else brackets.push(")");
  };
  makeList(n);
};
