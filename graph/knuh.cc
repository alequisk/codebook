struct Kuhn {
  vector<vector<int>> adj;
  vector<int> matchA, matchB, marcB;
  int n, m;
  bool matched = false;
  Kuhn(int n, int m) : n(n), m(m) {
    adj.resize(n, vector<int>());
    matchA.resize(n);
    matchB = marcB = vector<int>(m);
  }
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    matched = false;
  }
  bool dfs(int u) {
    for (int &v : adj[u]) {
      if (marcB[v]) continue;
      marcB[v] = 1;
      if (matchB[v] == -1 or dfs(matchB[v])) {
        matchB[v] = u;
        matchA[u] = v;
        return true;
      }
    }
    return false;
  }
  int matching() {
    for (int i = 0; i < n; i++) matchA[i] = -1;
    for (int i = 0; i < m; i++) matchB[i] = -1;
    /*shuffle(td(adj), rng); // se o grafo pode ser esparso
    for(auto v : adj) shuffle(td(v), rng);*/

    int res = 0;
    bool aux = true;
    while (aux) {
      for (int j = 0; j < m; j++) marcB[j] = 0;
      aux = false;
      for (int i = 0; i < n; i++) {
        if (matchA[i] != -1) continue;
        if (dfs(i)) {
          res++;
          aux = true;
        }
      }
    }
    matched = true;
    return res;
  }
};