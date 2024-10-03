#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl dp;

ll solve(ll x) {
  if (dp[x] < 0) {
    dp[x] = numeric_limits<ll>::max();
    if (x >= 7) {
      dp[x] = min(dp[x], 1 + solve(x - 7));
    }
    if (x >= 5) {
      dp[x] = min(dp[x], 1 + solve(x - 5));
    }
    if (x >= 2) {
      dp[x] = min(dp[x], 1 + solve(x - 2));
    }
    if (x >= 1) {
      dp[x] = min(dp[x], 1 + solve(x - 1));
    }
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  dp = vl(n + 8, -1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[5] = 1;
  dp[7] = 1;

  cout << solve(n);

  return 0;
}