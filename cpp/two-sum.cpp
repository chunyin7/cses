#include <iostream>
#include <vector>
#include <map>

int main() {
  int n, x; 
  std::cin >> n >> x;

  std::vector<int> nums(n);
  for (int &num : nums) {
    std::cin >> num;
  }

  std::map<int, int> seen;
  for (int i{0}; i < n; i++) {
    int target = x - nums[i];
    auto it = seen.find(target);
    if (it != seen.end()) {
      std::cout << it->second + 1 << ' ' << i + 1 << '\n';
      return 0;
    }
    seen[nums[i]] = i;
  }
  std::cout << "IMPOSSIBLE\n";
  return 0;
}
