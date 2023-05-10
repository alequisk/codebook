#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

const bool areTest = 0;

#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)

using ll = int64_t;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const char nl = '\n';
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void run_test(int testcase) {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);

  int t = 1;
  if (areTest) cin >> t;
  for (int i = 1; i <= t; i++) {
    run_test(i);
  }

  return 0;
}