/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  let i = 0;
  let j = nums.length - 1;
  let ans = nums.length;
  while (i <= j) {
    let mid = i + Math.floor((j - i) / 2);

    if (nums[mid] < nums[0]) {
      ans = mid;
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
  if (target >= nums[0]) {
    i = 0;
    j = ans - 1;
  } else {
    i = ans;
    j = nums.length - 1;
  }
  ans = -1;
  while (i <= j) {
    let mid = i + Math.floor((j - i) / 2);
    if (nums[mid] === target) {
      ans = mid;
      j = mid - 1;
    } else if (nums[mid] > target) {
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }

  return ans;
};
