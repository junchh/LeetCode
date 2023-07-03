/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  if (nums.length < 3) {
    return [];
  } else {
    let ans = [];
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      let target = -1 * nums[i];
      let j = i + 1;
      let k = nums.length - 1;
      while (j < k) {
        if (nums[j] + nums[k] === target) {
          if (nums[j] != nums[j - 1] || nums[k] != nums[k + 1]) {
            ans.push([nums[i], nums[j], nums[k]]);
          }
          j++;
          k--;
        } else if (nums[j] + nums[k] < target) {
          j++;
        } else {
          k--;
        }
      }
    }
    return ans;
  }
};
