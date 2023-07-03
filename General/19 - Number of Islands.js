/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
  const mov = [
    [1, 0],
    [0, 1],
    [-1, 0],
    [0, -1],
  ];
  const m = grid.length;
  const n = grid[0].length;

  var visited = [];
  for (let i = 0; i < grid.length; i++) {
    var inner = [];
    for (let j = 0; j < grid[i].length; j++) {
      inner.push(false);
    }
    visited.push(inner);
  }
  var dfs = function (a, b) {
    visited[a][b] = true;

    const st = [];
    st.push([a, b]);
    while (st.length !== 0) {
      let fr = st.pop();

      for (let i = 0; i < 4; i++) {
        let nexta = fr[0] + mov[i][0];
        let nextb = fr[1] + mov[i][1];
        if (
          nexta >= 0 &&
          nexta < m &&
          nextb >= 0 &&
          nextb < n &&
          grid[nexta][nextb] === "1" &&
          !visited[nexta][nextb]
        ) {
          visited[nexta][nextb] = true;
          st.push([nexta, nextb]);
        }
      }
    }
  };

  let ans = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (!visited[i][j] && grid[i][j] === "1") {
        ans++;
        dfs(i, j);
      }
    }
  }
  return ans;
};
