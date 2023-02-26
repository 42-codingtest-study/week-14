//문제: 9465
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  let T = +input.shift();
  for (let i = 0; i < T; i++) {
    const arr = [];
    let n = +input.shift();
    arr.push(input.shift().split(" ").map(Number));
    arr.push(input.shift().split(" ").map(Number));
    const dp = [
      [arr[0][0], arr[0][1] + arr[1][0]],
      [arr[1][0], arr[1][1] + arr[0][0]],
    ];
    // console.log(arr);
    for (let i = 2; i < n; i++) {
      dp[0][i] = Math.max(dp[1][i - 2], dp[1][i - 1]) + arr[0][i];
      dp[1][i] = Math.max(dp[0][i - 2], dp[0][i - 1]) + arr[1][i];
    }
    console.log(Math.max(dp[0][n - 1], dp[1][n - 1]));
  }
}
