/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let m = [];
  for (let i = 0; i < nums.length; i++) {
    m.push({ i: i, val: nums[i] });
  }

  m.sort((a, b) => a.val - b.val);

  let i = 0;
  let j = nums.length - 1;
  let ans = [];
  while (i < j) {
    if (m[i].val + m[j].val === target) {
      ans.push(m[i].i);
      ans.push(m[j].i);
      break;
    } else if (m[i].val + m[j].val < target) {
      i++;
    } else {
      j--;
    }
  }
  return ans;
};
