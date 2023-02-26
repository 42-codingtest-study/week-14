//문제: 2410
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  dp = new Array(1000000).fill(0n);
  dp[1] = 1n;
  dp[2] = 2n;

  for (let i = 3; i < 1000001; i++) {
    if (i % 2) dp[i] = dp[i - 1];
    else dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000n;
  }
  console.log(dp[+input[0]].toString());
}
