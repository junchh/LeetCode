/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  intervals.sort((a, b) => {
    if (a[0] === b[0]) {
      return a[1] - b[1];
    } else {
      return a[0] - b[0];
    }
  });

  let le = intervals[0][0];
  let ri = intervals[0][1];
  let ans = [];
  for (let i = 1; i < intervals.length; i++) {
    if (intervals[i][0] <= ri) {
      ri = Math.max(ri, intervals[i][1]);
    } else {
      ans.push([le, ri]);
      le = intervals[i][0];
      ri = intervals[i][1];
    }
  }
  ans.push([le, ri]);
  return ans;
};
