#include <iostream>

using namespace std;

int board[101][101] = { {0,} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		int tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		for(int y = tmp_y; y < tmp_y + 10; y++) {
			for(int x = tmp_x; x < tmp_x + 10; x++) {
				if(board[y][x] == 1) {
					continue;
				}
				board[y][x] = 1;
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
} 