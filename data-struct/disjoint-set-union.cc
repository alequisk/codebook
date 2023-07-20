#include <bits/stdc++.h>

class UnionSet {
 private:
  std::vector<int> parent;
  std::vector<int> size;
  void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
  }

 public:
  UnionSet(int n) {
    parent.resize(n + 1);
    size.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) {
      make_set(i);
    }
  }
  int find_set(int v) {
    if (parent[v] == v)
      return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (size[a] < size[b]) {
      std::swap(a, b);
    }
    parent[b] = a;
    size[a] += b;
  }
  bool is_same(int a, int b) {
    return find_set(a) == find_set(b);
  }
  int get_size(int v) {
    return size[find_set(v)];
  }
};