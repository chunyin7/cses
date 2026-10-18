#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
  int modulo = 1000000007;
  int n;
  std::cin >> n;

  std::vector<unsigned long int> dp(std::max(6, n));
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 4;
  dp[3] = 8;
  dp[4] = 16;
  dp[5] = 32;
  for (int i{6}; i < n; i++) {
    dp[i] = (dp[i - 6] + dp[i - 5] + dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1]) % modulo;
  }
  std::cout << dp[n - 1] << '\n';
  return 0;
}
