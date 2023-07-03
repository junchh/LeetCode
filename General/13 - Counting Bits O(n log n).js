/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function (n) {
  let ans = [];
  for (let i = 0; i <= n; i++) {
    let cnt = 0;
    let x = i;
    while (x > 0) {
      cnt += x % 2;
      x = Math.floor(x / 2);
    }
    ans.push(cnt);
  }
  return ans;
};
