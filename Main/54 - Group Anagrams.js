/**
 * @param {string[]} strs
 * @return {string[][]}
 */

const sortString = (s) => {
  let arr = [];
  for (let i = 0; i < s.length; i++) {
    arr.push({ code: s.charCodeAt(i), val: s[i] });
  }

  arr.sort((a, b) => a.code - b.code);
  let arr2 = [];
  for (let i = 0; i < s.length; i++) {
    arr2.push(arr[i].val);
  }
  return arr2.join("");
};
var groupAnagrams = function (strs) {
  const mp = new Map();
  for (let i = 0; i < strs.length; i++) {
    const key = sortString(strs[i]);
    if (mp.has(key)) {
      mp.get(key).push(strs[i]);
    } else {
      mp.set(key, [strs[i]]);
    }
  }
  let ans = [];
  mp.forEach((value) => {
    ans.push(value);
  });
  return ans;
};
