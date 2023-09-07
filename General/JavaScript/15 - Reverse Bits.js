/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function (n) {
  var strForm = n.toString(2);
  while (strForm.length != 32) {
    strForm = "0" + strForm;
  }

  return parseInt(strForm.split("").reverse().join(""), 2);
};
