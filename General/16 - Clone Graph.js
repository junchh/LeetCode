/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function (node) {
  if (node === null) {
    return null;
  }
  const vis = new Map();
  let ans = new Node(node.val, []);
  vis.set(node.val, ans);
  let st = [[node, ans]];
  while (st.length != 0) {
    let fr = st[st.length - 1];
    st.pop();

    for (let i = 0; i < fr[0].neighbors.length; i++) {
      if (!vis.has(fr[0].neighbors[i].val)) {
        let newNode = new Node(fr[0].neighbors[i].val, []);
        vis.set(fr[0].neighbors[i].val, newNode);
        st.push([fr[0].neighbors[i], newNode]);
        fr[1].neighbors.push(newNode);
      } else {
        fr[1].neighbors.push(vis.get(fr[0].neighbors[i].val));
      }
    }
  }
  return ans;
};
