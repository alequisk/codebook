struct Node {
  Node() {
    // empty or neutral node
    val = 0;
  }

  Node(int _val) {
    // create new node for seg3
    val = _val;
  }

  Node(Node a, Node b) {
    // combine of segtree
    val = a.val + b.val;
  }

  // atributes
  int val;
};

// 0-based [l, r]
template<class i_t, class i_e>
class SegmentTree {
  public:
    void build(vector<i_e> &arr) {
      size = (int) arr.size();
      segment_tree.assign(4 * size, i_t());
      build(arr, 1, 0, size - 1);
    }
 
    void build(vector<i_e> &arr, int x, int lx, int rx) {
      if(lx == rx) {
        segment_tree[x] = i_t(arr[lx]);
      } else {
        int mid = (lx + rx) / 2;
        build(arr, (x << 1), lx, mid);
        build(arr, (x << 1) | 1, mid + 1, rx);
        segment_tree[x] = i_t(segment_tree[(x << 1)], segment_tree[(x << 1) | 1]);
      }
    }
 
    void update(int i, i_e v, int x, int lx, int rx) {
      if(lx == rx) {
        segment_tree[x] = i_t(v);
      } else {
        int mid = (lx + rx) / 2;
        if(i <= mid) {
          update(i, v, (x << 1), lx, mid);
        } else {
          update(i, v, (x << 1) | 1, mid + 1, rx);
        }
        segment_tree[x] = i_t(segment_tree[(x << 1)], segment_tree[(x << 1) | 1]);
      }
    }
 
    void update(int i, i_e v) {
      update(i, v, 1, 0, size - 1);
    }
 
    i_t query(int x, int lx, int rx, int l, int r) {
      if(lx > r or rx < l)
        return i_t();
      if(lx >= l and rx <= r)
        return segment_tree[x];
      int mid = (lx + rx) / 2;
      return i_t(query((x << 1), lx, mid, l, r), query((x << 1) | 1, mid + 1, rx, l, r));
    }
 
    i_t query(int l, int r) {
      return query(1, 0, size - 1, l, r);
    }

  private:
    int size;
    vector<i_t> segment_tree;
};

// call example:
// SegmentTree<Node, int> seg;
// seg.build(arr);