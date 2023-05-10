#define LENGTH 20
#define TIGHT 2
#define NUM_SUM 1500

int tick;
ll memo[LENGTH][TIGHT][NUM_SUM];
int seen[LENGTH][TIGHT][NUM_SUM];

ll digitDp(string& digits, int index, int tight, int numSum) {
  if (index == -1) {
    return (ll)numSum;
  }
  ll& dp = memo[index][tight][numSum];
  int& saw = seen[index][tight][numSum];

  if (saw == tick and !tight) {
    return dp;
  }

  saw = tick;

  ll answer = 0;
  int mx = tight ? (digits[index] - '0') : 9;
  for (int nextDigit = 0; nextDigit <= mx; nextDigit++) {
    int newTight = (digits[index] - '0') == nextDigit ? tight : 0;
    answer += digitDp(digits, index - 1, newTight, numSum + nextDigit);
  }

  if (!tight) {
    dp = answer;
  }
  return answer;
}

ll solve(ll x) {
  if (x == -1) return 0;
  string digits = to_string(x);
  int length = len(digits);
  reverse(digits.begin(), digits.end());
  ++tick;
  return digitDp(digits, length - 1, 1, 0);
}