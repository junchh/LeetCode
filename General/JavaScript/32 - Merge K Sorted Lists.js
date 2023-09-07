/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
var mergeTwoLists = function (list1, list2) {
  let newNode = null;

  let cur = null;

  while (list1 || list2) {
    if (list1 && list2) {
      if (newNode === null) {
        if (list1.val <= list2.val) {
          newNode = list1;
          list1 = list1.next;
          cur = newNode;
        } else {
          newNode = list2;
          list2 = list2.next;
          cur = newNode;
        }
      } else {
        if (list1.val <= list2.val) {
          cur.next = list1;
          cur = cur.next;
          list1 = list1.next;
        } else {
          cur.next = list2;
          cur = cur.next;
          list2 = list2.next;
        }
      }
    } else if (list1) {
      if (newNode === null) {
        newNode = list1;
        list1 = list1.next;
        cur = newNode;
      } else {
        cur.next = list1;
        list1 = list1.next;
        cur = cur.next;
      }
    } else {
      if (newNode === null) {
        newNode = list2;
        list2 = list2.next;
        cur = newNode;
      } else {
        cur.next = list2;
        cur = cur.next;
        list2 = list2.next;
      }
    }
  }
  return newNode;
};

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
  if (lists.length === 0) {
    return null;
  } else if (lists.length === 1) {
    return lists[0];
  } else if (lists.length === 2) {
    return mergeTwoLists(lists[0], lists[1]);
  } else {
    let cur = lists[0];

    for (let i = 1; i < lists.length; i++) {
      const temp = mergeTwoLists(cur, lists[i]);
      cur = temp;
    }
    return cur;
  }
};
