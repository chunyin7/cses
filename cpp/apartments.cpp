#include <iostream>
#include <algorithm>

int main() {
  int n, m, k;
  std::cin >> n;
  std::cin >> m;
  std::cin >> k;

  int applicants[n];
  for (int i{0}; i < n; i++) {
    std::cin >> applicants[i];
  }
  std::sort(applicants, applicants + n);
  int apartments[m];
  for (int i{0}; i < m; i++) {
    std::cin >> apartments[i];
  }
  std::sort(apartments, apartments + m);

  int l{0};
  int ret{0};
  for (int a : applicants) {
    while (l < m && apartments[l] < a - k) {
      l++;
    }
    if (l >= m) {
      break;
    }
    if (apartments[l] <= a + k) {
      ret++;
      l++;
    }
  }

  std::cout << ret << "\n";

  return 0;
}
