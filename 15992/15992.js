//문제: 15992
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  let n = +input.shift();
  const dp = new Array(1001).fill(0).map(() => new Array(1001).fill(0));
  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 1;
  dp[3][2] = 2;
  dp[3][3] = 1;
  for (let i = 4; i <= 1000; i++) {
    for (let j = 1; j <= 1000; j++) {
      dp[i][j] =
        (((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % 1000000009) +
          dp[i - 3][j - 1]) %
        1000000009;
    }
  }
  for (let i = 0; i < n; i++) {
    const [a, b] = input.shift().split(" ").map(Number);
    console.log(dp[a][b]);
  }
}
