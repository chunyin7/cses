#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, n + 1);
  dp[n] = 0;
  for (int i{n}; i >= 0; i--) {
    int j = i;
    while (j != 0) {
      int digit = j % 10;
      if (i >= digit) {
        dp[i - digit] = std::min(dp[i - digit], 1 + dp[i]);
      }
      j /= 10;
    }
  }

  std::cout << dp[0] << '\n';
  return 0;
}
