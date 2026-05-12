for(let i = 0; i < 5; i++) {
  console.log(i);
}

let arr = [1, 2, 3, 4, 5];

let left = 0;
let right = arr.length - 1;

while (left < right) {
  [arr[left], arr[right]] = [arr[right], arr[left]];
  left++;
  right--;
}

console.warn(arr);