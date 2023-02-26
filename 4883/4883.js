//문제: 4883
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  let line = +input.shift();
  const arr = input.map((e) => e.split(" "));
  const dp = new Array(line);
  dp[0] = +arr[0][1];
  for (let i = 1; i < line; i++) {
    const temp = [];
    for (let j = 0; j < 3; j++) {
      temp.push(dp[i - 1] + +arr[i][j] - +arr[i - 1][1]);
    }
    console.log(temp);
    dp[i] = Math.min(...temp);
  }
  console.log(dp);
}
