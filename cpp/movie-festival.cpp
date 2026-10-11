#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::array<int, 2>> movies;
  for (int i{0}; i < n; i++) {
    std::array<int, 2> movie;
    std::cin >> movie[0] >> movie[1];
    movies.push_back(movie);
  }
  std::sort(movies.begin(), movies.end(), [](std::array<int, 2> a, std::array<int, 2> b) {
    return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
  });
  int cur_end{-1}, ret{0};
  for (std::array<int, 2> m : movies) {
    if (m[0] >= cur_end) {
      ret++;
      cur_end = m[1];
    }
  }

  std::cout << ret << '\n';
  return 0;
}
