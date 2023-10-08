#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, b) for (int i = (0); i < (b); i++)
#define debug(x) cout << "[" #x << "] = " << x << '\n'

typedef int64_t ll;
typedef pair<int, int> ii;

#define nl '\n'
const bool areTest = 0;

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