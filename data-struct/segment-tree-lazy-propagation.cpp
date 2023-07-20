#include <bits/stdc++.h>

// 1-based tree node
#define Left(x) ((x << 1))
#define Right(x) ((x << 1) | 1)

struct LazyContext {
  LazyContext() {}                         /* !! Initial Lazy value !! */
  LazyContext(int x) {}                    /* !! Assigned Lazy value !! */
  void reset() {}                          /* !! Reset Values of Lazy !! */
  void operator+=(const LazyContext& o) {} /* !! Join Lazys [Increment Lazys] */
  /* !! Properties of Lazy !! */
};
struct NodeSegTree {
  NodeSegTree() {}                     /* !! Neutral NodeSegTree !! */
  NodeSegTree(int x) {}                /* !! Assign NodeSegTree !! */
  void apply(const LazyContext& lz) {} /* !! Apply context to NodeSegTree !! */
  /* !! Properties of NodeSegTree !! */
};

/* !! Join NodeSegTree implementation !! */
NodeSegTree operator+(const NodeSegTree& lhs, const NodeSegTree& rhs) {
  NodeSegTree res;
  // Code goes here!
  return res;
}

class SegmentTree {
 private:
  size_t size;
  std::vector<bool> dirty;
  std::vector<NodeSegTree> tree;
  std::vector<LazyContext> lazy;

  void unlazy(int node, int tl, int tr) {
    if (!dirty[node]) return;
    tree[node].apply(lazy[node]);
    if (tl != tr) {
      dirty[Left(node)] = dirty[Right(node)] = true;
      lazy[Left(node)] += lazy[node];
      lazy[Right(node)] += lazy[node];
    }
    lazy[node].reset();
    dirty[node] = false;
  }
  /* !! Change type of value [val] !! */
  void update(int node, int tl, int tr, int l, int r, int val) {
    unlazy(node, tl, tr);
    if (tl > r or tr < l)
      return;
    if (tl >= l && tr <= r) {
      lazy[node] = LazyContext(val);
      dirty[node] = true;
      unlazy(node, tl, tr);
      return;
    }
    int mid = (tl + tr) >> 1;
    update(Left(node), tl, mid, l, r, val);
    update(Right(node), mid + 1, tr, l, r, val);
    tree[node] = tree[Left(node)] + tree[Right(node)];
  }

  NodeSegTree query(int node, int tl, int tr, int l, int r) {
    unlazy(node, tl, tr);
    if (tr < l or tl > r)
      return NodeSegTree();
    if (tl >= l && tr <= r) {
      return tree[node];
    }
    int mid = (tl + tr) >> 1;
    return query(Left(node), tl, mid, l, r) + query(Right(node), mid + 1, tr, l, r);
  }

  /* !! Change type of array !! */
  void build(const std::vector<int>& v, int node, int tl, int tr) {
    lazy[node].reset();
    if (tl == tr) {
      tree[node] = NodeSegTree(v[tl]);
    } else {
      int mid = (tl + tr) >> 1;
      build(v, Left(node), tl, mid);
      build(v, Right(node), mid + 1, tr);
      tree[node] = tree[Left(node)] + tree[Right(node)];
    }
  }

 public:
  /* !! Change type of build array !! */
  void init(const std::vector<int>& a) {
    size = a.size();
    lazy.resize(4 * size);
    tree.resize(4 * size);
    dirty.assign(4 * size, false);
    build(a, 1, 0, size - 1);
  }

  NodeSegTree query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }

  /* !! Change type of update value !! */
  void update(int l, int r, int val) {
    update(1, 0, size - 1, l, r, val);
  }
};