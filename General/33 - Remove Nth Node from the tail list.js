/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
  let front = head;
  let i = head;
  let j = head;
  let cnt = 0;
  while (j) {
    if (cnt < n) {
      cnt++;
      j = j.next;
    } else {
      if (j.next === null) {
        console.log(j.val);
        let del = i.next;
        i.next = del.next;
        break;
      } else {
        i = i.next;
        j = j.next;
      }
    }
  }
  // if the deleted node is in the middle
  if (j !== null) {
    return front;
  } else {
    // if its the front
    return front.next;
  }
};
