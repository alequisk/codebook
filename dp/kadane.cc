/**
  Kadane's algorithm.
  This algorithm returns the max contiguous subarray sum
  from array.
*/

#define len(x) ((int)(x).size())

template<typename T>
int64_t kadane(vector<T>& a) {
  int64_t currentSum = 0, maxSum = -1e9;
  int n = len(a);
  for (int i = 0; i < n; i++) {
    currentSum += a[i];
    if (currentSum > maxSum) {
      maxSum = currentSum;
    }
    if (currentSum < 0) {
      currentSum = 0;
    }
  }
  return maxSum;
}