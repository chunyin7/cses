#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arrivals, leavings;
  int arrival, leaving;
  for (int i{0}; i < n; i++) {
    std::cin >> arrival >> leaving;
    arrivals.push_back(arrival);
    leavings.push_back(leaving);
  }
  std::sort(arrivals.begin(), arrivals.end());
  std::sort(leavings.begin(), leavings.end());
  int cur{0}, b{0}, ret{0};
  for (int a{0}; a < n; a++) {
    cur++;
    if (leavings[b] <= arrivals[a]) {
      b++;
      cur--;
    }
    if (cur > ret) ret = cur;
  }

  std::cout << ret << '\n';
  return 0;
}
