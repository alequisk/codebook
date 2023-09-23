/* Binary Index Tree 1-based, queries [l, r] */
/* When using range_add the queries answers is in point */
template <class T>
class FenwichTree {
 private:
  int size, LN;
  std::vector<T> ft;

 public:
  FenwichTree(int size) : size(size), LN(0) {
    ft.assign(size + 1, 0);
    while (1 << (LN + 1) <= size) ++LN;
  }
  void add(int i, T delta) {
    for (; i <= size; i += (i & -i))
      ft[i] += delta;
  }
  T qry(int i) {
    T sum = 0;
    for (; i > 0; i -= (i & -i))
      sum += ft[i];
    return sum;
  }
  T qry(int l, int r) { return qry(r) - qry(l - 1); }
  void range_add(int left, int right, T delta) {
    add(left, delta);
    add(right + 1, -delta);
  }
  int findKthSmallest(T value) {
    T sum = 0;
    int pos = 0;
    for (int k = LN; k >= 0; k--) {
      int next_pos = pos + (1 << k);
      if (next_pos <= size && sum + ft[next_pos] < value) {
        sum += ft[next_pos];
        pos = next_pos;
      }
    }
    return pos + 1;  // is lower bound, when put equals is upper bound
  }
};