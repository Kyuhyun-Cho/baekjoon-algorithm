#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int board[n][n]{};
	int dp[n][n]{};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> board[i][j];
			dp[i][j] = board[i][j];
		}
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			dp[i-1][j] = dp[i-1][j] + max(dp[i][j], dp[i][j+1]);
		}
	}
	
	cout << dp[0][0] << '\n';

	return 0;
}