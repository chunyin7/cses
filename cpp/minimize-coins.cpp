#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> coins(n); 
  for (int &coin : coins) {
    std::cin >> coin;
  }

  std::vector<long int> dp(x + 1, x + 1);
  dp[0] = 0;
  for (int i{1}; i <= x; i++) {
    for (int coin : coins) {
      if (i >= coin) {
        dp[i] = std::min(1 + dp[i - coin], dp[i]);
      }
    }
  }

  if (dp[x] == x + 1) dp[x] = -1;
  std::cout << dp[x] << '\n';
  return 0;
}
