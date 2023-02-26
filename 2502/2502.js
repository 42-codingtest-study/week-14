//문제: 2502
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [a, b] = input[0].split(" ").map(Number);
  const memories = [1, 1];
  for (let i = 2; i <= a; i++) {
    memories.push(memories[i - 2] + memories[i - 1]);
  }
  let a1 = memories[a - 3];
  let b1 = memories[a - 2];
  for (let i = 1; i <= b; i++) {
    let x = (b - a1 * i) / b1;
    if (x > 0 && x == Math.floor(x)) return console.log(`${i}\n${x}`);
  }
}
