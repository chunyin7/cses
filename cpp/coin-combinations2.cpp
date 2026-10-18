#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int modulo = 1000000007;
  int n, x;
  std::cin >> n >> x;

  std::vector<int> coins(n);
  for (int &coin : coins) {
    std::cin >> coin;
  }
  std::sort(coins.begin(), coins.end());

  std::vector<int> prev(x + 1), cur(x + 1);
  prev[0] = 1;
  cur[0] = 1;
  for (int i{0}; i < n; i++) {
    for (int j{1}; j <= x; j++) {
      cur[j] = prev[j];
      if (j >= coins[i]) {
        cur[j] += cur[j - coins[i]];
      }
      cur[j] %= modulo;
    }

    prev = cur;
    cur = std::vector<int>(x + 1);
    cur[0] = 1;
  }
  std::cout << prev[x] << '\n';
  return 0;
}
