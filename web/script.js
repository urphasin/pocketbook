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


class SocialGraph {
  constructor(vertices) {
    this.adj = new Map();
    let m = this.adj;

    vertices.forEach(person => this.adj.set(person, []));
  }

  addFriendship(a, b) {
    this.adj.get(a).push(b);
    this.adj.get(b).push(a);
  }

  print() {
    for (let [k, v] of this.adj) {
      console.log(k , " -> ",  v.join(", "))
    }
  }
}

const social = new SocialGraph(["Ava", "Max", "Anna", "Plummet", "Woodgrove", "Cosby"])
social.addFriendship("Ava", "Max")
social.print()