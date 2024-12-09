class MaxHeap {
    constructor() {
      this.heap = [];
    }
  
    insert(value) {
      this.heap.push(value);
      this.bubbleUp();
    }
  
    bubbleUp() {
      let index = this.heap.length - 1;
      while (index > 0) {
        let parentIndex = Math.floor((index - 1) / 2);
        if (this.heap[parentIndex][0] >= this.heap[index][0]) break;
        [this.heap[parentIndex], this.heap[index]] = [this.heap[index], this.heap[parentIndex]];
        index = parentIndex;
      }
    }
  
    extractMax() {
      if (this.heap.length === 1) return this.heap.pop();
      const max = this.heap[0];
      this.heap[0] = this.heap.pop();
      this.bubbleDown();
      return max;
    }
  
    bubbleDown() {
      let index = 0;
      const length = this.heap.length;
      while (true) {
        let leftChildIndex = 2 * index + 1;
        let rightChildIndex = 2 * index + 2;
        let largest = index;
  
        if (leftChildIndex < length && this.heap[leftChildIndex][0] > this.heap[largest][0]) {
          largest = leftChildIndex;
        }
        if (rightChildIndex < length && this.heap[rightChildIndex][0] > this.heap[largest][0]) {
          largest = rightChildIndex;
        }
        if (largest === index) break;
        [this.heap[index], this.heap[largest]] = [this.heap[largest], this.heap[index]];
        index = largest;
      }
    }
  
    isEmpty() {
      return this.heap.length === 0;
    }
}

const dijkstra = (n, edges, start, end) => {
    const graph = Array.from({ length: n + 1 }, () => []);

    // 그래프 구성
    for (const [u, v, w] of edges) {
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }

    const maxHeap = new MaxHeap();
    const maxWeight = Array(n + 1).fill(0);
    maxWeight[start] = Infinity;

    maxHeap.insert([Infinity, start]);

    while (!maxHeap.isEmpty()) {
        const [weight, node] = maxHeap.extractMax();

        if (node === end) return weight;

        for (const [nextNode, limit] of graph[node]) {
        const nextWeight = Math.min(weight, limit);
        if (nextWeight > maxWeight[nextNode]) {
            maxWeight[nextNode] = nextWeight;
            maxHeap.insert([nextWeight, nextNode]);
        }
        }
    }

    return 0; // 연결되지 않은 경우
};
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
rl.on('line', (line) => {
  input.push(line.trim());
}).on('close', () => {
  // 입력 처리
  const [n, m] = input[0].split(' ').map(Number);
  const edges = [];
  for (let i = 1; i <= m; i++) {
    const [u, v, w] = input[i].split(' ').map(Number);
    edges.push([u, v, w]);
  }
  const [start, end] = input[m + 1].split(' ').map(Number);

  // 다익스트라 호출 및 결과 출력
  console.log(dijkstra(n, edges, start, end));
});
