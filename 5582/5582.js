//문제: 5582
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  let str1 = input[0];
  let str2 = input[1];

  let answer = 0;

  let LCS = new Array(str1.length + 1);
  for (let i = 0; i < LCS.length; i++) {
    LCS[i] = new Array(str2.length + 1).fill(0);
  }

  for (let i = 1; i <= str1.length; i++) {
    for (let j = 1; j <= str2.length; j++) {
      if (str1[i - 1] === str2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
      else LCS[i][j] = 0;

      if (LCS[i][j] > answer) answer = LCS[i][j];
    }
  }
  console.log(answer);
}
