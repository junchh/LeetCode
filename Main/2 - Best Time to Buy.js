/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let curMax = prices[prices.length - 1];
  let ans = 0;
  for (let i = prices.length - 2; i >= 0; i--) {
    ans = Math.max(ans, curMax - prices[i]);
    curMax = Math.max(curMax, prices[i]);
  }
  return ans;
};
