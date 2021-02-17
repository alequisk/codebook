// segment tree with lazy
int segment_tree[4 * N], lazy[4 * N];

void pushup(int v) {
  segment_tree[v] = segment_tree[v<<1] + segment_tree[v<<1|1];
}

void pushdown(int v, int tl, int tr) {
  if (lazy[v]) {
    int tm = (tl + tr) >> 1;
    // covering all left side of child node
    segment_tree[v<<1] = tm - tl + 1;
    // covering all right side of child node
    segment_tree[v<<1|1] = tr - tm;
    // adding lazy to childs
    lazy[v<<1] = lazy[v<<1|1] = 1;
    lazy[v] = 0;
    pushup(v);
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    segment_tree[v] = lazy[v] = 0;
  } else {
    int tm = (tr + tl) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    pushup(v);
  }
}

void build(int n) { build(1, 1, n); }

int get(int v, int tl, int tr, int x) {
  if (tr == tl) {
    // getting the node
    return segment_tree[v];
  }
  // resolving the lazy
  pushdown(v, tl, tr);
  int tm = (tl + tr) >> 1;
  if (x <= tm) {
    return get(v << 1, tl, tm, x);
  } else {
    return get(v << 1 | 1, tm + 1, tr, x);
  }
}

int get(int n, int x) { return get(1, 1, n, x); }

void update(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return;
  if (tl == l and tr == r) {
    segment_tree[v] = r - l + 1;
    lazy[v] = 1;
  } else {
    // resolving lazy
    pushdown(v, tl, tr);
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm));
    update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
  }
}

void update(int n, int l, int r) { update(1, 1, n, l, r); }