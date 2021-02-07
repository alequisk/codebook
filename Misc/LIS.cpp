#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define len(x) (int)(x).size()
#define trav(a,x) for (auto& a : x)
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int MOD = 1000000007;
const char nl = '\n';

int longestIncreasingSubsequence(vector<int> &arr) {
  vector<int> lis;
  trav(x, arr) {
    int id = ub(all(lis), x) - lis.begin();
    if (id == len(lis)) lis.pb(x);
    else lis[id] = x;
  }
  return len(lis);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  trav(i, a)
    cin >> i;

  cout << longestIncreasingSubsequence(a) << nl;

  return 0;
}