#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int board[n][n]{};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			board[i-1][j] = board[i-1][j] + max(board[i][j], board[i][j+1]);
		}
	}
	
	cout << board[0][0] << '\n';

	return 0;
}