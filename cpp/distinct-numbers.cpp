#include <set>
#include <iostream>
#include <sstream>

int main() {
  int n;
  std::cin >> n;

  int num;
  std::set<int> nums;
  for (int i{0}; i < n; i++) {
    std::cin >> num;
    if (!nums.contains(num)) {
      nums.insert(num);
    }
  }
  std::cout << nums.size() << "\n";
  return 0;
}
