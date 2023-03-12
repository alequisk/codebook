#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())

using ll = int64_t;
const char nl = '\n';

template<typename T>
int64_t kadane(vector<T>& a) {
  int64_t currentSum = 0, maxSum = -1e9;
  for (int i = 0; i < len(a); i++) {
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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << kadane(a) << nl;

  return 0;
}