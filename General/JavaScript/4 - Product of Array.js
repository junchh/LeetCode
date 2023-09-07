/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  const pref = Array(nums.length);
  const suf = Array(nums.length);

  pref[0] = nums[0];
  suf[nums.length - 1] = nums[nums.length - 1];
  for (let i = 1; i < nums.length; i++) {
    pref[i] = pref[i - 1] * nums[i];
  }
  for (let i = nums.length - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] * nums[i];
  }

  let ans = Array(nums.length);
  for (let i = 0; i < nums.length; i++) {
    if (i === 0) {
      ans[i] = suf[1];
    } else if (i === nums.length - 1) {
      ans[i] = pref[nums.length - 2];
    } else {
      ans[i] = pref[i - 1] * suf[i + 1];
    }
  }
  return ans;
};
