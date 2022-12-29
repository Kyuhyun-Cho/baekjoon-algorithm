#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int board[101][101]{};
	int paper[n][4];
	for (int i = 0; i < n; i++) {
		cin >> paper[i][0] >> paper[i][1] >> paper[i][2] >> paper[i][3];
	}

	for (int i = 0; i < n; i++) {
		for (int j = paper[i][0]; j <= paper[i][2]; j++) {
			for (int k = paper[i][1]; k <= paper[i][3]; k++) {
				board[j][k] += 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if(board[i][j] > m) cnt++;
		}
	}
	cout << cnt << '\n';
}