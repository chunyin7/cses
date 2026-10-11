#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int x, n;
  std::cin >> n >> x;
  std::vector<int> weights(n);
  for (int &weight : weights) {
    std::cin >> weight;
  }
  std::sort(weights.begin(), weights.end());

  int ret{n};
  int l{0};
  int r{n - 1};
  while (l <= r) {
    if (l != r && weights[l] + weights[r] <= x) {
      ret--;
      l++;
    }
    r--;
  }

  std::cout << ret << '\n';
}
