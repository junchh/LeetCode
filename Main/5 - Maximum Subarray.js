/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
  const prefix = Array(nums.length);
  const fmin = Array(nums.length);

  prefix[0] = nums[0];
  fmin[0] = nums[0];
  let ans = nums[0];
  for (let i = 1; i < nums.length; i++) {
    prefix[i] = prefix[i - 1] + nums[i];
    ans = Math.max(ans, prefix[i] - fmin[i - 1]);
    ans = Math.max(ans, prefix[i]);
    fmin[i] = Math.min(fmin[i - 1], prefix[i]);
  }
  return ans;
};
