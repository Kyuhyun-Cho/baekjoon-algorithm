#include <iostream>

using namespace std;

int N;
int board[129][129]{};

int zero_cnt = 0;
int one_cnt = 0;

int white = 0;
int blue = 0;

void div(int n, int x, int y) {
	zero_cnt = 0;
	one_cnt = 0;
	for (int i = x ; i < x+n; i++){
		for (int j = y; j < y+n; j++) {
			if (board[i][j] == 0) zero_cnt++;
			else if (board[i][j] == 1) one_cnt++;
		}
	}
	if (zero_cnt == n*n) white++;
	else if (one_cnt == n*n) blue++;
	else {
		div(n/2, x, y);
		div(n/2, x+n/2, y);
		div(n/2, x, y+n/2);
		div(n/2, x+n/2, y+n/2);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	div(N, 0, 0);

	cout << white << '\n' << blue << '\n';
}