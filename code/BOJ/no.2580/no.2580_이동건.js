// 참고 코드. 직접 푼 건 아님

const data = require("fs")
  .readFileSync("/dev/stdin", "utf8")
  .toString()
  .trim()
  .split("\n");

const row = "123456789"
  .split("")
  .map((_) => "1234567890".split("").map((j) => !Boolean(j)));
const col = "123456789"
  .split("")
  .map((_) => "1234567890".split("").map((j) => !Boolean(j)));
const box = "123456789"
  .split("")
  .map((_) => "1234567890".split("").map((j) => !Boolean(j)));

let shouldFill = [];
const shouldFillComplete = [];
let shouldStop = false;

const sudoku = data.map((x, i) =>
  x.split(" ").map((y, j) => {
    const v = Number(y);
    if (v === 0) {
      shouldFill.push([i, j, Math.floor(i / 3) + 3 * Math.floor(j / 3)]);
      shouldFillComplete.push(false);
    } else {
      row[i][v] = true;
      col[j][v] = true;
      box[Math.floor(i / 3) + 3 * Math.floor(j / 3)][v] = true;
    }
    return v;
  })
);
let answer = "";
const solve = (n) => {
  if (n === shouldFillComplete.length) {
    shouldStop = true;
    return;
  }
  // n번째 빈 칸을 채운다
  if (!shouldStop) {
    for (let i = 1; i < 10; i++) {
      if (
        !row[shouldFill[n][0]][i] &&
        !col[shouldFill[n][1]][i] &&
        !box[shouldFill[n][2]][i]
      ) {
        shouldFillComplete[n] = true;
        row[shouldFill[n][0]][i] = true;
        col[shouldFill[n][1]][i] = true;
        box[shouldFill[n][2]][i] = true;
        sudoku[shouldFill[n][0]][shouldFill[n][1]] = i;
        solve(n + 1);
        if (!shouldStop) {
          shouldFillComplete[n] = false;
          row[shouldFill[n][0]][i] = false;
          col[shouldFill[n][1]][i] = false;
          box[shouldFill[n][2]][i] = false;
          sudoku[shouldFill[n][0]][shouldFill[n][1]] = 0;
        }
      }
    }
  }
};

solve(0);

sudoku.forEach((row) => {
  answer += row.join(" ");
  answer += "\n";
});

console.log(answer);