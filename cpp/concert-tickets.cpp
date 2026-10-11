#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::multiset<int> tickets;
  for (int i{0}; i < n; i++) {
    int ticket;
    std::cin >> ticket;
    tickets.insert(-ticket);
  }

  int price;
  while (std::cin >> price) {
    int best{-1};
    auto ticket = tickets.find(-price);
    if (ticket == tickets.end()) ticket = tickets.upper_bound(-price);
    if (ticket != tickets.end()) {
      best = *ticket * -1;
      tickets.erase(ticket);
    }
    std::cout << best << '\n';
  }

  return 0;
}
