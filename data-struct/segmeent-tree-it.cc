struct Node {
  Node() {}     // default to neutral
  Node(...) {}  // setting values
};

Node comp(Node a, Node b) {
}

class SegmentTree {
  int n;
  std::vector<Node> a;

 public:
  SegmentTree(std::vector<int> const& base) {
    n = (int)base.size();
    a.resize(n << 1);
    for (int i = 0; i < n; i++) {
      a[i + n] = Node(base[i]);
    }
    for (int i = n - 1; i > 0; i--)
      a[i] = comp(a[i + i], a[i + i + 1]);
  }
  void update(int i, ll x) {
    a[i += n] = Node(x);  // substitui
    for (i >>= 1; i > 0; i >>= 1)
      a[i] = comp(a[i + i], a[i + i + 1]);
  }
  Node query(int l, int r) {
    Node lp, rp;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lp = comp(lp, a[l++]);
      if (r & 1) rp = comp(a[--r], rp);
    }
    return comp(lp, rp);
  }
};