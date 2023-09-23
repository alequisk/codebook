#include <bits/stdc++.h>

template <class T>
class SparseTable {
 private:
  int K, N;
  std::vector<std::vector<T>> st;
  std::function<T(T, T)> comp;

 public:
  template <typename ForwardIterator>
  SparseTable(ForwardIterator begin, ForwardIterator end, const std::function<T(T, T)> &comp) {
    this->comp = comp;
    K = 1, N = end - begin;
    while ((1 << K) <= N)
      ++K;
    st.assign(K, std::vector<T>(N));
    std::copy(begin, end, st[0].begin());
    for (int i = 1; i < K; i++)
      for (int j = 0; j + (1 << (i - 1)) < N; j++)
        st[i][j] = comp(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }

  T query(int L, int R) {
    assert(L <= R);
    int i = 31 - __builtin_clz(R - L + 1);
    return comp(st[i][L], st[i][R - (1 << i) + 1]);
  }
};