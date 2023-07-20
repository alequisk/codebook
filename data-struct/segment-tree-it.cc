#include <bits/stdc++.h>

struct Node {
  Node() {}
  Node(int x) {}
  Node operator+(const Node& o) {
    Node res;
    return res;
  }
};

class SegmentTree {
 private:
  int n;
  std::vector<Node> a;

 public:
  SegmentTree(const std::vector<int>& base) {
    n = base.size();
    a.resize(n << 1);
    for (int i = 0; i < n; i++) {
      a[i + n] = Node(base[i]);
    }
    for (int i = n - 1; i > 0; i--)
      a[i] = a[i + i] + a[i + i + 1];
  }
  void update(int i, int x) {
    a[i += n] = Node(x);  // substitui, para adicionar colocar +
    for (i >>= 1; i > 0; i >>= 1)
      a[i] = a[i + i] + a[i + i + 1];
  }
  Node query(int l, int r) {
    Node lp, rp;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lp = lp + a[l++];
      if (r & 1) rp = a[--r] + rp;
    }
    return lp + rp;
  }
};