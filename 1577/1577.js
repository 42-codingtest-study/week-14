//문제: 1577
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [N, M] = input.shift().split(" ").map(Number);
  let k = +input.shift();

  let visited = new Array(201)
    .fill(false)
    .map(() => new Array(201).fill(false)); // 공사 지역 방문처리
  let dp = new Array(101).fill(0n).map(() => new Array(101).fill(0n));

  for (let i = 0; i < k; i++) {
    const [a, b, c, d] = input[i].split(" ").map(Number);
    visited[b + d][a + c] = true;
  }
  dp[0][0] = 1n;
  for (let i = 1; i <= M; ++i) {
    if (visited[2 * i - 1][0]) break;
    dp[i][0] = 1n;
  }

  // x 축 도로 초기화
  for (let i = 1; i <= N; ++i) {
    if (visited[0][2 * i - 1]) break;
    dp[0][i] = 1n;
  }

  // O(MN) 으로 돌면서 방문 가능한 지역에 한해서 경우의 수 계산
  for (let i = 1; i <= M; ++i) {
    for (let j = 1; j <= N; ++j) {
      if (!visited[2 * i - 1][2 * j]) dp[i][j] += dp[i - 1][j];

      if (!visited[2 * i][2 * j - 1]) dp[i][j] += dp[i][j - 1];
    }
  }

  console.log(dp[M][N].toString());
}
