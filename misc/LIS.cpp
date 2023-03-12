/**
  Longest Increasing Subsequence.
  Return the size of the maximim strictly increasing subsequence;
  for non strictly, use lowerbound instead of upperbound
*/

#define len(x) ((int)(x).size())

template<typename T>
int LIS(vector<T>& arr) {
  vector<T> arr;
  for (T x: arr) {
    int id = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
    if (id == len(lis)) {
      lis.push_back(x);
    } else {
      lis[id] = x;
    }
  }
  return len(lis);
}