/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function (nums) {
  let global_max = nums[0];
  let fmax = nums[0];
  let fmin = nums[0];

  for (let i = 1; i < nums.length; i++) {
    if (fmax === 0 && fmin === 0) {
      fmax = nums[i];
      fmin = nums[i];
    } else {
      if (nums[i] === 0) {
        fmax = 0;
        fmin = 0;
      } else if (nums[i] > 0) {
        fmax = Math.max(nums[i] * fmax, nums[i]);
        fmin = Math.min(nums[i] * fmin, nums[i]);
      } else {
        let temp = fmax;
        fmax = Math.max(nums[i], nums[i] * fmin);
        fmin = Math.min(nums[i], nums[i] * temp);
      }
    }
    global_max = Math.max(global_max, fmax);
  }
  return global_max;
};
