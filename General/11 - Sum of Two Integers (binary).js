/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function (a, b) {
  let x = a;
  let y = b;
  let result = 0;
  while (y != 0) {
    let m = x ^ y;
    let n = (x & y) << 1;
    x = m;
    y = n;
  }
  return x;
};
