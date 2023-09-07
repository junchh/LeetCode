/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function (n) {
  let ans = [0];
  let cur = 1;
  for (let i = 1; i <= n; i++) {
    if (!(i & (i - 1))) {
      ans.push(1);
      cur = i;
    } else {
      ans.push(ans[i - cur] + 1);
    }
  }
  return ans;
};
