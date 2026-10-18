#include <iostream>
#include <vector>

int main() {
  int modulo = 1000000007;
  int n, x;
  std::cin >> n >> x;

  std::vector<int> coins(n);
  for (int &coin : coins) {
    std::cin >> coin;
  }

  std::vector<int> dp(x + 1);
  dp[0] = 1;
  for (int i{1}; i <= x; i++) {
    for (int coin : coins) {
      if (i >= coin) {
        dp[i] += dp[i - coin];
        dp[i] %= modulo;
      }
    }
  }

  std::cout << dp[x] << '\n';
  return 0;
}
