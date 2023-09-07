/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  const mp = new Map();

  let cur = head;
  while (cur) {
    if (mp.has(cur)) {
      return true;
    } else {
      mp.set(cur, 1);
      cur = cur.next;
    }
  }
  return false;
};
