/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let arr = [];
  for (let i = 0; i < height.length; i++) {
    arr.push([height[i], i]);
  }

  arr.sort((a, b) => a[0] - b[0]);

  let ans = 0;
  let suf_max = Array(arr.length);
  let suf_min = Array(arr.length);
  suf_max[arr.length - 1] = arr[arr.length - 1][1];
  suf_min[arr.length - 1] = arr[arr.length - 1][1];
  for (let i = arr.length - 2; i >= 0; i--) {
    suf_max[i] = Math.max(suf_max[i + 1], arr[i][1]);
    suf_min[i] = Math.min(suf_min[i + 1], arr[i][1]);
  }

  for (let i = 0; i < arr.length - 1; i++) {
    ans = Math.max(
      ans,
      Math.max(
        arr[i][0] * Math.abs(arr[i][1] - suf_max[i + 1]),
        arr[i][0] * Math.abs(arr[i][1] - suf_min[i + 1])
      )
    );
  }
  return ans;
};
