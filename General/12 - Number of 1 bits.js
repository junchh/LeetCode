/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
  let cnt = 0;
  let x = n;
  while (x > 0) {
    cnt += x % 2;
    x = Math.floor(x / 2);
  }
  return cnt;
};
