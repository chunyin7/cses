#include <iostream>
#include <vector>

int main() {
  int modulo = 1000000007;
  int n;
  std::cin >> n;

  std::vector<std::vector<char>> board(n, std::vector<char>(n));
  for (int i{0}; i < n; i++) {
    for (int j{0}; j < n; j++) {
      std::cin >> board[i][j];
    }
  }

  std::vector<std::vector<int>> dp(n, std::vector<int>(n));
  if (board[0][0] != '*') dp[0][0] = 1;
  for (int i{0}; i < n; i++) {
    for (int j{0}; j < n; j++) {
      if (board[i][j] == '*') {
        continue;
      }
      if (i >= 1 && board[i - 1][j] != '*') {
        dp[i][j] += dp[i - 1][j];
      }
      if (j >= 1 && board[i][j - 1] != '*') {
        dp[i][j] += dp[i][j - 1];
      }
      dp[i][j] %= modulo;
    }
  }

  std::cout << dp[n - 1][n - 1] << '\n';
  return 0;
}
