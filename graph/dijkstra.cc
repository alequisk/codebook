#include<vector>
#include<queue>

#define INF 1000000000

std::vector<std::vector<int>> graph;
using dtype = std::tuple<int,int>;

void dijkstra(int source, int sz) {
  std::vector<int> dist(sz + 1, INF);
  std::vector<bool> marked(sz + 1, false);
  dist[source] = 0;
  std::priority_queue<dtype, std::vector<dtype>, std::greater<dtype>> pq;
  pq.push((0, source));
  while (!pq.empty()) {
    int u = (pq.front()).get(1);
    pq.pop();
    if (marked[u]) continue;
    for (auto v: graph[u]) {
      
    }
  }
}
